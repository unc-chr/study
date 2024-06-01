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
#include <memory>
#include <mutex>
#include <queue>
#include <vector>

// Any 类型：可以接收任意数据的类型
class Any {
    private:
        // 基类类型
        class Base {
            public:
                virtual ~Base() = default;
        };
        // 派生类类型
        template<typename T>
        class Derive : public Base {
            public:
                T data_;
                Derive(T data) : data_(data) {}
        }
    private:
        // 定义一个基类的指针
        std::unique_ptr<Base> base_;
    public:
        Any() = default;
        ~Any() = default;
        Any(const Any&) = delete;
        Any& operator=(const Any&) = delete;
        Any(Any&&) = default;
        Any& operator=(Any&&) = default;

        // 该构造函数允许 Any 类型接受其他任意类型的数据
        template<typename T>
        Any(T data) : base_(std::make_unique<Derive<T>>(data)) {}
        // Any(T data) : base_(new Derive<T>(data)) {}

        // 将 Any 对象中存储的其他类型的对象提取出来。
        template<typeanme T>
        T cast_() {
            // 从 base_ 中找到它所指向的 Derive 对象，从里面取出 data 成员变量
            // 基类指针 =》 派生类指针
            Derive<T>* pd = dynamic_cast<Derive<T>*>(base_.get());
            if (pd == nullptr) {
                throw "type is incompatiable!";
            }
            return pd->data_;
        }
};

// 线程执行的任务抽象基类
// 用户可以自定义任意任务类型，从 Task 继承，重写 run 方法
class Task {
    public:
        // 作为工作线程的回调函数
        virtual void run() = 0;
};

// 线程池支持的模式
enum ThreadPoolMode {
    MODE_FIXED,   // 固定数量的线程
    MODE_CACHED  // 线程数量可动态增长
};

// 线程类型
class Thread {
    public:
        // 线程函数对象类型
        using ThreadFunc = std::function<void()>;
        // 构造函数
        Thread(ThreadFunc func);
        // 析构函数
        ~Thread();
        // 启动线程，线程会执行一个函数
        void start();
    private:
        ThreadFunc func;
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
        // queue 中的元素使用裸指针是不安全的。
        // 用户传入的可能是一个生命周期较短的对象。
        // 必须延长其生命周期，等待 run 函数执行完毕。
        // 所以使用智能指针。
        std::queue<std::shared_ptr<Task>> task_queue;   
        // 线程列表，列表元素使用智能指针，防止内存泄漏
        std::vector<std::unique_ptr<Thread>> thread_workers;
        // 初始的线程数量
        size_t init_thread_size_;            
        // 任务的数量。不同线程都会访问并修改，是共享资源。
        // 需要实现原子访问。互斥锁太重了，原子变量效率更高。
        std::atomic_uint task_size;         
        // 任务队列数量上限阈值
        size_t task_queue_max_thresh_hold;    
        // 当前线程池的工作模式
        ThreadPoolMode pool_mode;           
        // 保证任务队列的线程安全
        std::mutex task_queue_mtx;          
        // 任务队列不满，通知：允许提交任务
        std::condition_variable not_full;   
        // 任务队列不空，通知：允许提取任务
        std::condition_variable not_empty;  

    private:
        // 线程函数
        void thread_func();

    public:
        // 线程池构造
        ThreadPool();                                       
        // 线程池析构 
        ~ThreadPool();                                      
        // 开启线程池
        void start(int init_thread_size = 2);                 
        // 设置线程池的工作模式
        void set_mode(ThreadPoolMode mode);                                    
        // 设置 task 任务队列上限阈值
        void set_task_queue_max_thresh_hold(int thresh_hold);              
        // 给线程池提交任务
        void submit_task(std::shared_ptr<Task> task);       
        // 禁止拷贝构造，没必要拷贝一整个线程池
        ThreadPool(const ThreadPool&) = delete;             
        // 禁止赋值构造，没必要将一整个线程池赋值
        ThreadPool& operator=(const ThreadPool&) = delete;  
};

#endif