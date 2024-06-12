/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：thread_pool.cpp
*   Author：leekaihua
*   Date：20240610
*   Brife：
*

*/

#include <iostream>

#include "any.h"
#include "result.h"

#include "thread_pool.h"

const int TASK_QUEUE_CAPACITY = 4;
const int THREAD_WORKERS_MAX_CAPACITY = 2;
const int THREAD_MAX_IDLE_TIME = 60;    // 单位 秒

ThreadPool::ThreadPool() {
    task_queue_capacity_ = TASK_QUEUE_CAPACITY;
    task_queue_curr_size_ = 0;
    thread_workers_max_capacity_ = THREAD_WORKERS_MAX_CAPACITY;
    thread_workers_init_size_ = 0;
    thread_workers_curr_size_ = 0;
    thread_workers_idle_size_ = 0;
    thread_pool_mode_ = THREAD_MODE::MODE_FIXED;
    is_running_ = false;
}

ThreadPool::~ThreadPool() {
    std::cerr << "ThreadPool destroy begin ..." << std::endl;
    is_running_ = false;

    std::unique_lock<std::mutex> lock(mtx);
    // 通知所有的线程，执行一遍任务
    // 1 获取到任务的就赶紧执行
    // 2 没获取到任务的，判断 is_running_ 的状态并退出
    cv_not_empty.notify_all();
    // 所有任务执行完毕，队列为空，可以退出
    cv_exit_.wait(lock, [&]()->bool {return task_queue_curr_size_ == 0;});
    std::cerr << "ThreadPool destroy finished..." << std::endl;
}

void ThreadPool::set_thread_pool_mode(THREAD_MODE mode) {
    // 线程池启动后，不允许更改状态
    if (is_running_ == true) {
        return;
    }
    thread_pool_mode_ = mode;
}

void ThreadPool::set_thread_workers_capacity(int task_queue_capacity) {
    thread_workers_max_capacity_ = task_queue_capacity;
}

void ThreadPool::set_task_queue_capacity(int task_queue_capacity) {
    task_queue_capacity_ = task_queue_capacity;
}

void ThreadPool::start(size_t thread_workers_init_size) {
    // 更改线程池的状态
    is_running_ = true;
    // 创建工作线程
    for (size_t i = 0; i < thread_workers_init_size; i++) {
        std::unique_ptr<Thread> ptr = 
                std::make_unique<Thread>(std::bind(&ThreadPool::thread_work, this, std::placeholders::_1));
        int thread_id = ptr->get_id();
        thread_workers_.emplace(thread_id, std::move(ptr));
    }
    // 启动工作线程
    for (size_t i = 0; i < thread_workers_init_size; i++) {
        thread_workers_[i]->start();
    }
    thread_workers_init_size_ = thread_workers_init_size;
    thread_workers_idle_size_ = thread_workers_init_size;
    thread_workers_curr_size_ = thread_workers_init_size;
}

Result ThreadPool::submit_task(std::shared_ptr<Task> task) {
    // cached 模式下，可能需要增加线程数量
    if (thread_pool_mode_ == THREAD_MODE::MODE_CACHED
            && task_queue_curr_size_ > thread_workers_idle_size_
            && thread_workers_curr_size_ < thread_workers_max_capacity_) {
        std::cout << ">>> create new thread <<<" << std::endl;
        std::unique_ptr<Thread> ptr = 
                std::make_unique<Thread>(std::bind(&ThreadPool::thread_work, this, std::placeholders::_1));
        int thread_id = ptr->get_id();
        thread_workers_.emplace(thread_id, std::move(ptr));
        thread_workers_[thread_id]->start();
        thread_workers_curr_size_++;
        thread_workers_idle_size_++;
    }
    {
        // 先抢锁
        std::unique_lock<std::mutex> lock(mtx);
        // 任务可能会提交失败，场景是：
        // 所有的线程都在工作，任务队列已满，超过1s未能等候到任务队列不满的通知
        if(!cv_not_full.wait_for(lock, 
                            std::chrono::seconds(1),
                            [&]()->bool {return !is_task_queue_full();})) {
            std::cerr << "submit failed" << std::endl;
            return Result(task, "submit failed!", false);
        }
<<<<<<< HEAD
        // 提交任务
        task_queue_.emplace(task);
        task_queue_curr_size_++;
=======
        task_queue_.emplace(task);
>>>>>>> ea0b157a383426cc37a838bc57a6cd57af61813b
        // 出作用域，释放锁
    }
    // 通知消费者
    cv_not_empty.notify_all();
    // 这行不能用，后续再研究
    // return std::move(Result(task, "submit success!"));
    return Result(task, "submit success!");
}

void ThreadPool::thread_work(int thread_id) {
    // 线程需要一直运行
    auto last_time = std::chrono::high_resolution_clock::now();
    while (true) {
        std::shared_ptr<Task> task;
        {
            // 先抢锁
            std::unique_lock<std::mutex> lock(mtx);
            // 如果线程池要结束，且当前已经无任务，那么销毁当前线程
            while (is_task_queue_empty()) {
                if (is_running_ == false) {
                    thread_workers_.erase(thread_id);
                    thread_workers_curr_size_--;
                    thread_workers_idle_size_--;
                    std::cout << "current thread: " << thread_id << " finished!" << std::endl;
                    cv_exit_.notify_all();
                    // 当前线程结束了。
                    return;
                }
                // 如果线程池正常运行中
                if (thread_pool_mode_ == THREAD_MODE::MODE_CACHED) {
                    // 每隔一秒，就确认是否达到了60s等待限制
                    if (std::cv_status::timeout == cv_not_empty.wait_for(lock, std::chrono::seconds(1))) {
                        auto now = std::chrono::high_resolution_clock::now();
                        auto dur = std::chrono::duration_cast<std::chrono::seconds>(now - last_time);
                        if (dur.count() >= THREAD_MAX_IDLE_TIME
                                && thread_workers_curr_size_ > thread_workers_init_size_) {
                            thread_workers_.erase(thread_id);
                            thread_workers_curr_size_--;
                            thread_workers_idle_size_--;
                            std::cout << "current thread: " << thread_id << " finished!" << std::endl;
                            // 当前线程结束了。
                            return;
                        }
                    }
                } else {
                    cv_not_empty.wait(lock);
                }
            }
            // 任务执行可能非常耗时，所以尽快释放锁
            task = task_queue_.front();
            task_queue_.pop();
            task_queue_curr_size_--;
            thread_workers_idle_size_--;
        }
        // 通知生产者可以提交任务
        cv_not_full.notify_all();
        if (task == nullptr) {
            std::cerr << "error: task = nullptr!" << std::endl;
        } else {
            task->exec();
        }
        thread_workers_idle_size_++;
        last_time = std::chrono::high_resolution_clock::now();
    }
}