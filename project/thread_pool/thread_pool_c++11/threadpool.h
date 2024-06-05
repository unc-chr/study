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
        };
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
        template<typename T>
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


// 信号量，类似 C++20 支持的信号量
class Semaphore {
public:
    // 构造函数，支持指定默认资源计数
    Semaphore(int limit = 0) : res_limit_(limit), is_exit_(false) {}
    ~Semaphore() {
        is_exit_ = true;
    }
    // 获取一个信号量资源
    void wait() {
        if (is_exit_) {
            return;
        }
        std::unique_lock<std::mutex> lock(mtx_);
        // 等待信号量有资源，没有资源的话，会阻塞当前线程
        cond_.wait(lock, [&]()->bool {return res_limit_ > 0;});
        res_limit_--;
    }
    // 增加一个信号量资源
    void post() {
        if (is_exit_) {
            return;
        }
        std::unique_lock<std::mutex> lock(mtx_);
        res_limit_++;
        cond_.notify_all();
    }
private:
    // 资源计数
    int res_limit_;
    // 判断信号量是否析构，如果析构，wait 和 post 就无意义了。
    std::atomic_bool is_exit_;
    std::mutex mtx_;
    std::condition_variable cond_;
};


// Task 类型的前置声明
class Task;
// Result: 任务提交到线程池，执行完毕之后的返回值类型
class Result {
public:
    Result(std::shared_ptr<Task> task, bool is_vaild = true);
    ~Result() = default;

    // set value 方法，获取任务执行完的返回值
    void set_value(Any any);

    // get 方法，用户调用该方法获取 task 的返回值
    Any get();

private:
    // 存储任务的返回值
    Any any_;  

    // 线程通信信号量
    Semaphore sem_;

    // 返回值是否有效
    std::atomic_bool is_vaild_;

    // 指向要获取返回值的任务对象
    std::shared_ptr<Task> task_;
};


// 线程执行的任务抽象基类
// 用户可以自定义任意任务类型，从 Task 继承，重写 run 方法
class Task {
public:
    Task();
    ~Task() = default;
    void exec();
    void set_result(Result* res);

    // 作为工作线程的回调函数
    virtual Any run() = 0;
private:
    // Result 对象的生命周期长于 Task
    Result* result_;
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
        using ThreadFunc = std::function<void(int)>;
        // 构造函数
        Thread(ThreadFunc func);
        // 析构函数
        ~Thread();
        // 启动线程，线程会执行一个函数
        void start();

        // 获取线程id
        int get_id() const;
    private:
        static int generate_id_;
        ThreadFunc func_;
        // 保存线程id
        int thread_id_;
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