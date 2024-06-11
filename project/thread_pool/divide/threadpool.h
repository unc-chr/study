/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：threadpool.h
*   Author：leekaihua
*   Date：20240601
*   Brife：
*



*/
#ifndef __THREADPOOL_H
#define __THREADPOOL_H

#include <atomic>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include <unordered_map>

#include "any.h"
#include "result.h"
#include "semaphore.h"
#include "thread.h"


// 线程池支持的模式
enum ThreadPoolMode {
    MODE_FIXED,   // 固定数量的线程
    MODE_CACHED  // 线程数量可动态增长
};


/*
thread pool class.
example:
ThreadPool pool;
pool.start(4);
class MyTask : public Task {
    public:
        void run() {//code}
}
pool.submit_task(std::make_shared<MyTask>());
*/
class ThreadPool {
    private:
        // 线程列表，列表元素使用智能指针，防止内存泄漏
        // thread_id_ => thread_pointer
        std::unordered_map<int, std::unique_ptr<Thread>> thread_workers;
        // 初始的线程数量
        size_t thread_workers_init_size_;            
        // 空闲线程的数量
        std::atomic_uint thread_workers_idle_size_;
        // 线程数量上限阈值
        unsigned int thread_workers_max_size_;
        // 线程池中线程的总数量
        std::atomic_uint thread_workers_curr_size_;

        // queue 中的元素使用裸指针是不安全的。
        // 用户传入的可能是一个生命周期较短的对象。
        // 必须延长其生命周期，等待 run 函数执行完毕。
        // 所以使用智能指针。
        std::queue<std::shared_ptr<Task>> task_queue;   
        // 任务的数量。不同线程都会访问并修改，是共享资源。
        // 需要实现原子访问。互斥锁太重了，原子变量效率更高。
        std::atomic_uint task_size_;         
        // 任务队列数量上限阈值
        size_t task_queue_max_size_;    
        // 保证任务队列的线程安全
        std::mutex task_queue_mtx;          
        // 任务队列不满，通知：允许提交任务
        std::condition_variable not_full;   
        // 任务队列不空，通知：允许提取任务
        std::condition_variable not_empty;  

        // 当前线程池的工作模式
        ThreadPoolMode pool_mode_;           
        // 当前线程池的启动状态
        // 多个线程都可能访问该值，故设计为原子类型
        std::atomic_bool is_pool_running_;
        // 等待线程资源全部回收
        std::condition_variable exit_cond_;

    private:
        // 线程函数
        void thread_func(int thread_id);

        // 检查线程池的运行状态
        bool check_running_state() const;

    public:
        // 线程池构造
        ThreadPool();                                       
        // 线程池析构 
        ~ThreadPool();                                      
        // 开启线程池
        void start(int init_thread_size = std::thread::hardware_concurrency());                 
        // 设置线程池的工作模式
        void set_mode(ThreadPoolMode mode);                                    
        // 设置 task 任务队列上限阈值
        void set_task_queue_max_thresh_hold(int thresh_hold);              
        // 给线程池提交任务
        Result submit_task(std::shared_ptr<Task> task);       
        // 禁止拷贝构造，没必要拷贝一整个线程池
        ThreadPool(const ThreadPool&) = delete;             
        // 禁止赋值构造，没必要将一整个线程池赋值
        ThreadPool& operator=(const ThreadPool&) = delete;  
        // cached 模式下设置线程池的上限阈值
        void set_thread_workers_max_size(int size);
};


#endif
