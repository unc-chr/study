/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：threadpool.cpp
*   Author：leekaihua
*   Date：20240601
*   Brife：
*



*/
#include "threadpool.h"

#include <functional>
#include <iostream>
#include <thread>

const int TASK_MAX_THRESHHOLD = 4;

ThreadPool::ThreadPool()
        : init_thread_size_(4)
        , task_size(0)
        , task_queue_max_thresh_hold(TASK_MAX_THRESHHOLD)
        , pool_mode(ThreadPoolMode::MODE_FIXED) {

}

ThreadPool::~ThreadPool() {

}

void ThreadPool::set_mode(ThreadPoolMode mode) {
    pool_mode = mode;
}

void ThreadPool::set_task_queue_max_thresh_hold(int thresh_hold) {
    task_queue_max_thresh_hold = thresh_hold;
}

void ThreadPool::submit_task(std::shared_ptr<Task> sp) {
    // 获取锁
    std::unique_lock<std::mutex> lock(task_queue_mtx);

    // 线程的通信，等待任务队列有空闲的槽位
    // 用户提交任务，最长阻塞时间不能超过 1s；否则判断提交任务失败，返回。
    if (!not_full.wait_for(lock, std::chrono::seconds(1),
            [&]()->bool {return task_queue.size() < task_queue_max_thresh_hold;})) {
        std::cerr << "task queue is full, submit task fail!" << std::endl;
        return;
    }
    
    // 如果有空槽位，将任务放到任务队列中
    task_queue.emplace(sp);
    task_size++;

    // 使用 notEmpty 条件变量通知消费者，有任务可以执行了
    not_empty.notify_all();
}

void ThreadPool::start(int init_thread_size) {
    // 记录初始线程个数
    init_thread_size_ = init_thread_size;

    // 集中创建线程对象
    for (int i = 0; i < init_thread_size; i++) {
        auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::thread_func, this));
        thread_workers.emplace_back(std::move(ptr));
    }

    // 集中启动所有线程
    for (int i = 0; i < init_thread_size; i++) {
        thread_workers[i]->start();
    }
}

void ThreadPool::thread_func() {
    // std::cout << "begin threadFunc" << std::endl;
    // std::cout << "tid: " << std::this_thread::get_id() << std::endl;
    // std::cout << "end threadFunc" << std::endl;
    // 死循环，执行工作的线程要一直待命
    for (;;) {
        std::shared_ptr<Task> job;
        {
            // 获取锁
            std::unique_lock<std::mutex> lock(task_queue_mtx);
            std::cout << "tid: " << std::this_thread::get_id()
                    << " trying get a job." << std::endl;

            // 等待 not_empty 条件变量通知
            not_empty.wait(lock, [&]()->bool {return task_queue.size() > 0;});
            std::cout << "tid: " << std::this_thread::get_id()
                    << " got a job." << std::endl;

            // 如果不空，取一个任务出来
            job = task_queue.front();
            task_queue.pop();
            task_size--;

            // 如果依然有剩余任务，继续通知其他线程执行任务
            if (task_queue.size() > 0) {
                not_empty.notify_all();
            }

            // 取出一个任务，通知生产者可以继续提交生产任务
            not_full.notify_all();

            // 出作用域，及时释放锁
        }
        // 当前线程负责执行这个任务
        if (job != nullptr) {
            job->run();
        }
    }
}

//////////////// 线程方法实现 ////////////////

Thread::Thread(ThreadFunc v_func)
        : func(v_func) {

}

Thread::~Thread() {

}

void Thread::start() {
    // 创建一个线程来执行一个线程函数
    // 线程对象是t，线程函数是 func, func 是真正的线程。
    std::thread t(func);

    // 设置分离线程
    // t 本身是个局部变量，出作用域之后会析构，设置分离后，真正的线程（线程函数）可以存活。
    // 线程函数会等待任务到来并执行，其实际存在于线程容器中。
    t.detach();    
}