/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：thread_pool.h
*   Author：leekaihua
*   Date：20240610
*   Brife：
*



*/
#pragma once

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_map>

#include "any.h"
#include "result.h"
#include "task.h"
#include "thread.h"

enum THREAD_MODE {MODE_FIXED, MODE_CACHED};

class ThreadPool {
public:
    ThreadPool();
    // 禁用拷贝构造，因为没必要复制一个线程池，增加工作线程的容量即可。
    ThreadPool(const ThreadPool& other) = delete;
    // 移动复制也没必要
    ThreadPool(ThreadPool&& other) = delete;
    // 禁用赋值构造
    ThreadPool& operator=(const ThreadPool& other) = delete;
    // 禁用移动赋值构造
    ThreadPool& operator=(ThreadPool&& other) = delete;
    // 析构函数
    ~ThreadPool();

    // 设置线程池的工作模式
    void set_thread_pool_mode(THREAD_MODE mode);

    // 设置线程最大数量
    void set_thread_workers_capacity(int task_queue_capacity);

    // 设置任务队列的最大容量
    void set_task_queue_capacity(int task_queue_capacity);

    // 启动线程池
    // 创建指定数量的工作线程
    void start(size_t thread_workers_init_size = std::thread::hardware_concurrency());

    // 提交任务，并给予一个反馈，该反馈信息返回给用户，类型是 Result
    Result submit_task(std::shared_ptr<Task> task);

private:
    // 工作线程的工作函数
    void thread_work(int thread_id);
    // 判断任务队列是否已满
    bool is_task_queue_full() {
        return task_queue_curr_size_ == task_queue_capacity_;
    }
    // 判断任务队列是否为空
    bool is_task_queue_empty() {
        return task_queue_.empty();
    }

private:
    // 线程池的属性
    // 线程池的工作模式
    THREAD_MODE thread_pool_mode_;
    // 线程池的启停状态
    bool is_running_;
    // 线程池等待退出的条件变量
    std::condition_variable cv_exit_;

    // 任务队列相关的属性
    // 任务队列
    std::queue<std::shared_ptr<Task>> task_queue_;
    // 任务队列容量
    size_t task_queue_capacity_;
    // 任务队列中当前任务的数量
    std::atomic_uint task_queue_curr_size_;
    // 任务队列的条件变量，用于同步，队列不空，可以取任务并执行
    std::condition_variable cv_not_empty;
    // 任务队列的条件变量，用于同步，队列不满，可以提交任务
    std::condition_variable cv_not_full;
    // 任务队列的互斥锁，辅助条件变量用于同步
    std::mutex mtx;

    // 线程容器相关的属性
    // 线程容器
    std::unordered_map<int, std::unique_ptr<Thread>> thread_workers_;
    // 线程容器的容量上限
    size_t thread_workers_max_capacity_;
    // 线程容器的初始容量，FIXED 模式下固定不变
    size_t thread_workers_init_size_;
    // 空闲线程数
    std::atomic_uint thread_workers_idle_size_;
    // 当前线程数
    std::atomic_uint thread_workers_curr_size_;
};