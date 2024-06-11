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

#define TASK_QUEUE_CAPACITY  10;
#define THREAD_WORKERS_MAX_CAPACITY 10;

ThreadPool::ThreadPool() {
    task_queue_capacity_ = TASK_QUEUE_CAPACITY;
    task_queue_curr_size_ = 0;
    thread_workers_max_capacity_ = THREAD_WORKERS_MAX_CAPACITY;
    thread_workers_init_size_ = 0;
    thread_pool_mode_ = THREAD_MODE::MODE_FIXED;
}

ThreadPool::~ThreadPool() {
    std::cerr << "ThreadPool destroy..." << std::endl;
}

Result ThreadPool::submit_task(std::shared_ptr<Task> task) {
    {
        // 先抢锁
        std::unique_lock<std::mutex> lock(mtx);
        while (is_task_queue_full()) {
            cv_not_full.wait(lock);
        }
        task_queue_.push(task);
        // 出作用域，释放锁
    }
    // 通知消费者
    cv_not_empty.notify_all();
    // 这行不能用，后续再研究
    // return std::move(Result(task, "submit success!"));
    return Result(task, "submit success!");
}

void ThreadPool::start(size_t thread_workers_init_size) {
    for (size_t i = 0; i < thread_workers_init_size; i++) {
        thread_workers_.emplace_back(std::thread(&ThreadPool::thread_work, this));
        thread_workers_[i].detach();
    }
}

void ThreadPool::thread_work() {
    // 线程需要一直运行
    while (true) {
        std::shared_ptr<Task> task;
        {
            // 先抢锁
            std::unique_lock<std::mutex> lock(mtx);
            while (is_task_queue_empty()) {
                cv_not_empty.wait(lock);
            }
            task_queue_curr_size_--;
            // 任务执行可能非常耗时，所以尽快释放锁
            task = task_queue_.front();
            task_queue_.pop();
        }
        // 通知生产者可以提交任务
        cv_not_full.notify_all();
        task->exec();
    }
}