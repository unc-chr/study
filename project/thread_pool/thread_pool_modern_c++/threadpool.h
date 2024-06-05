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
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include <unordered_map>


// 任务数量上限，开源的线程池一般是 INT32_MAX
const int TASK_MAX_THRESHHOLD = 2;
// 线程池线程数上限，依照资源合理设置
// 习惯上初始线程数等于 CPU 核数
const int THREAD_WORKERS_MAX_SIZE = 10;
// 线程空闲时间上限，这里设置的 60s
// 测试的时候快速看结果，可以设置 10s
const int THREAD_MAX_IDLE_TIME = 10;  // 单位：秒


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
        Thread(ThreadFunc func)
                : func_(func)
                , thread_id_(generate_id_++) {}

        // 析构函数
        ~Thread() = default;

        // 启动线程，线程会执行一个函数
        void start() {
            // 创建一个线程来执行一个线程函数
            // 线程对象是t，线程函数是 func, func 是真正的线程。
            std::thread t(func_, thread_id_);

            // 设置分离线程
            // t 本身是个局部变量，出作用域之后会析构，设置分离后，真正的线程（线程函数）可以存活。
            // 线程函数会等待任务到来并执行，其实际存在于线程容器中。
            t.detach();    
        }

        // 获取线程id
        int get_id() const {
            return thread_id_;
        }

    private:
        static int generate_id_;
        ThreadFunc func_;
        // 保存线程id
        int thread_id_;
};

int Thread::generate_id_ = 0;

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

        // queue 中的元素，应该是用户定义的函数，或者说函数对象。
        // 函数的参数可以通过 std::bind 实现和函数的绑定，但是函数的返回值如何处理？
        // 另外，Task 是类内部封装的，我们自己控制其生命周期，可以不使用智能指针。
        using Task = std::function<void()>;
        std::queue<Task> task_queue_;
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

        // 线程执行函数
        void thread_func(int thread_id) {
            // 死循环，执行工作的线程要一直待命
            auto last_time = std::chrono::high_resolution_clock().now();

            // 所有任务必须执行完成，线程池才可以回收所有线程资源
            while (true) {
                Task task;
                {
                    // 获取锁
                    std::cout << "tid: " << std::this_thread::get_id() << " waitting lock" << std::endl;
                    std::unique_lock<std::mutex> lock(task_queue_mtx);
                    std::cout << "tid: " << std::this_thread::get_id() << " got a lock" << std::endl;
                    std::cout << "tid: " << std::this_thread::get_id()
                            << " trying get a job." << std::endl;

                    while (task_queue_.size() == 0) {
                        if (!is_pool_running_) {
                            // 如果是执行任务中的线程，执行完发现 is_pool_running_ 为 false。
                            // 进入这个逻辑执行线程的销毁
                            thread_workers.erase(thread_id);
                            thread_workers_curr_size_--;
                            thread_workers_idle_size_--;
                            std::cout << "thread_id: " << std::this_thread::get_id() 
                                    << " finish job, and destroyed." << std::endl;
                            exit_cond_.notify_all();
                            return;
                        }

                        // cached 模式下，有可能已经创建了很多线程
                        // 空闲时间超过 60s，应该把多余的线程(超过thread_workers_init_size的)结束回收掉
                        if (pool_mode_ == ThreadPoolMode::MODE_CACHED) {
                            // 条件变量，如果返回是超时导致的，那么判断超时是否达到了60秒。
                            if (std::cv_status::timeout 
                                    == not_empty.wait_for(lock, std::chrono::seconds(1))) {
                                auto now = std::chrono::high_resolution_clock().now();
                                auto dur = std::chrono::duration_cast<std::chrono::seconds>(now - last_time);
                                if (dur.count() >= THREAD_MAX_IDLE_TIME
                                        && thread_workers_curr_size_ > thread_workers_init_size_) {
                                    // 回收当前线程
                                    // 记录线程数量的相关变量值的修改
                                    // 把线程对象从线程容器中剔除，但是没有办法区分 threadFunc <=> thread 对象
                                    // thread id => thread 对象 => 删除
                                    thread_workers.erase(thread_id);
                                    thread_workers_curr_size_--;
                                    thread_workers_idle_size_--;
                                    std::cout << "thread_id: " << std::this_thread::get_id() 
                                            << " exit." << std::endl;
                                    return;
                                }
                            } else {
                                // 如果返回是条件变量通知任务队列非空导致的，那么需要继续执行任务。
                                // 此时退出 while 循环，开始取任务并执行
                            }
                        } else {
                            // 等待 not_empty 条件变量通知
                            not_empty.wait(lock);
                        }
                    }

                    // 如果不空，取一个任务出来
                    task = task_queue_.front();
                    task_queue_.pop();
                    task_size_--;
                    thread_workers_idle_size_--;
                    std::cout << "tid: " << std::this_thread::get_id()
                            << " got a job." << std::endl;

                    // 如果依然有剩余任务，继续通知其他线程执行任务
                    if (task_queue_.size() > 0) {
                        not_empty.notify_all();
                    }

                    // 取出一个任务，通知生产者可以继续提交生产任务
                    not_full.notify_all();

                    // 出作用域，及时释放锁
                }
                // 当前线程负责执行这个任务
                if (task != nullptr) {
                    // 执行任务，把任务的返回值通过 set_value 方法给到 Result
                    task();
                }

                // 更新线程执行完任务的时间
                last_time = std::chrono::high_resolution_clock().now();
                // 成功执行完一个任务
                thread_workers_idle_size_++;
            }
        }

        // 检查线程池的运行状态
        bool check_running_state() const {
            return is_pool_running_;
        }

    public:
        // 线程池构造
        ThreadPool()
            : thread_workers_init_size_(4)
            , thread_workers_idle_size_(0)
            , thread_workers_max_size_(THREAD_WORKERS_MAX_SIZE)
            , thread_workers_curr_size_(0)
            , task_size_(0)
            , task_queue_max_size_(TASK_MAX_THRESHHOLD)
            , pool_mode_(ThreadPoolMode::MODE_FIXED)
            , is_pool_running_(false) {}

        // 线程池析构 
        ~ThreadPool() {
            is_pool_running_ = false;
            std::unique_lock<std::mutex> lock(task_queue_mtx);
            // 线程有两种状态（1）阻塞（2）执行任务中
            // 唤醒所有的线程，
            // 如果还有任务没有执行完毕，则执行任务。
            // 如果任务执行完毕，任务队列为空，那么就可以析构工作线程了。
            not_empty.notify_all();

            // 等待线程池中所有的线程返回
            // 条件变量 exit_cond 有通知，且 thread_workers.size() == 0
            // 那么就是可以退出了。
            exit_cond_.wait(lock, [&]()->bool {return thread_workers.size() == 0;});
        }

        // 开启线程池
        void start(int init_thread_size = std::thread::hardware_concurrency()) {
            // 设置线程池的启动状态
            is_pool_running_ = true;

            // 记录初始线程个数
            thread_workers_init_size_ = init_thread_size;
            thread_workers_curr_size_ = init_thread_size;

            // 集中创建线程对象
            for (size_t i = 0; i < thread_workers_init_size_; i++) {
                auto ptr = std::make_unique<Thread>(
                        std::bind(&ThreadPool::thread_func, this, std::placeholders::_1));
                int thread_id = ptr->get_id();
                thread_workers.emplace(thread_id, std::move(ptr));
            }

            // 集中启动所有线程
            for (size_t i = 0; i < thread_workers_init_size_; i++) {
                // 执行一个线程函数
                thread_workers[i]->start();
                // 记录初始空闲线程的数量
                thread_workers_idle_size_++;
            }
        }

        // 设置线程池的工作模式
        void set_mode(ThreadPoolMode mode) {
            // 线程池启动之后，不允许再次设置模式
            if (check_running_state()) {
                return;
            }
            pool_mode_ = mode;
        }

        // 设置 task 任务队列上限阈值
        void set_task_queue_max_thresh_hold(int thresh_hold) {
            task_queue_max_size_ = thresh_hold;
        }

        // 给线程池提交任务
        // 使用可变参模板编程，让 submit_task 可以接收任意任务函数和任意数量的参数
        // std::future<返回值类型>
        // 返回值类型为 auto，auto 的推断依据的是后置类型声明
        // 后置类型声明使用的是 decltype 语法，即具体的类型是 decltype 中表达式的类型，可以这么理解
        // submit_task 返回的是一个 std::future，但是使用 func(args) 的返回值来实例化的 std::future
        // func(args) 是用户提交的执行任务，func 是函数，args 是参数，且 args 支持变参
        // 由于 args 和 func 定义的时候使用的是右值引用，切合自动类型推断一起使用，所以成了万能引用。
        // 传入左值即左值引用，传入右值即右值引用
        template<typename Func, typename... Args>
        auto submit_task(Func&& func, Args&&... args) -> std::future<decltype(func(args...))> {
            // 打包任务，放到任务队列里面
            using ResType = decltype(func(args...));
            auto task = std::make_shared<std::packaged_task<ResType()>>(
                std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
            std::future<ResType> result = task->get_future();

            // 获取锁
            std::unique_lock<std::mutex> lock(task_queue_mtx);

            // 线程的通信，等待任务队列有空闲的槽位
            // 用户提交任务，最长阻塞时间不能超过 1s；否则判断提交任务失败，返回。
            if (!not_full.wait_for(lock, std::chrono::seconds(1),
                    [&]()->bool {
                        return task_queue_.size() < task_queue_max_size_;})) {
                std::cerr << "task queue is full, submit task fail!" << std::endl;
                auto task = std::make_shared<std::packaged_task<ResType()>>(
                    []()->ResType {return ResType();});
                (*task)();
                return task->get_future();
            }
            
            // 如果有空槽位，将任务放到任务队列中
            // task_queue_.emplace(sp);
            task_queue_.emplace([task]() {(*task)();});
            task_size_++;

            // 使用 notEmpty 条件变量通知消费者，有任务可以执行了
            not_empty.notify_all();

            // cached 模式下，任务处理比较紧急 适用场景：小而快的任务
            // 需要根据任务数量和空闲线程的数量，判断是否需要创建新的线程出来
            if (pool_mode_ == ThreadPoolMode::MODE_CACHED 
                    && task_size_ > thread_workers_idle_size_
                    && thread_workers_curr_size_ < thread_workers_max_size_) {
                // 创建额外的新线程
                std::cout << ">>> create new thread..." << std::endl;
                auto ptr = std::make_unique<Thread>(
                        std::bind(&ThreadPool::thread_func, this, std::placeholders::_1));
                int thread_id = ptr->get_id();
                thread_workers.emplace(thread_id, std::move(ptr));
                thread_workers[thread_id]->start();
                // 修改线程个数相关的变量
                thread_workers_curr_size_++;
                thread_workers_idle_size_++;
            }

            // 返回任务的 Result 对象
            return result;
        }

        // 禁止拷贝构造，没必要拷贝一整个线程池
        ThreadPool(const ThreadPool&) = delete;             
        // 禁止赋值构造，没必要将一整个线程池赋值
        ThreadPool& operator=(const ThreadPool&) = delete;  

        // cached 模式下设置线程池的上限阈值
        void set_thread_workers_max_size(int size) {
            if (check_running_state()) {
                return;
            }
            if (pool_mode_ == ThreadPoolMode::MODE_CACHED) {
                thread_workers_max_size_ = size;
            }
        }
};


#endif