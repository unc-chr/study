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

// 任务数量上限，开源的线程池一般是 INT32_MAX
const int TASK_MAX_THRESHHOLD = 100;
// 线程池线程数上限，依照资源合理设置
// 习惯上初始线程数等于 CPU 核数
const int THREAD_WORKERS_MAX_SIZE = 10;
// 线程空闲时间上限，这里设置的 60s
// 测试的时候快速看结果，可以设置 10s
const int THREAD_MAX_IDLE_TIME = 10;  // 单位：秒

ThreadPool::ThreadPool()
        : thread_workers_init_size_(4)
        , thread_workers_idle_size_(0)
        , thread_workers_max_size_(THREAD_WORKERS_MAX_SIZE)
        , thread_workers_curr_size_(0)
        , task_size_(0)
        , task_queue_max_size_(TASK_MAX_THRESHHOLD)
        , pool_mode_(ThreadPoolMode::MODE_FIXED)
        , is_pool_running_(false)
{
    std::cout << task_queue.size() << std::endl;
}

ThreadPool::~ThreadPool() {
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

void ThreadPool::set_mode(ThreadPoolMode mode) {
    // 线程池启动之后，不允许再次设置模式
    if (check_running_state()) {
        return;
    }
    pool_mode_ = mode;
}

void ThreadPool::set_task_queue_max_thresh_hold(int thresh_hold) {
    task_queue_max_size_ = thresh_hold;
}

void ThreadPool::set_thread_workers_max_size(int size) {
    if (check_running_state()) {
        return;
    }
    if (pool_mode_ == ThreadPoolMode::MODE_CACHED) {
        thread_workers_max_size_ = size;
    }
}

Result ThreadPool::submit_task(std::shared_ptr<Task> sp) {
    // 获取锁
    std::unique_lock<std::mutex> lock(task_queue_mtx);

    // 线程的通信，等待任务队列有空闲的槽位
    // 用户提交任务，最长阻塞时间不能超过 1s；否则判断提交任务失败，返回。
    if (!not_full.wait_for(lock, std::chrono::seconds(1),
            [&]()->bool {
                return task_queue.size() < task_queue_max_size_;})) {
        std::cerr << "task queue is full, submit task fail!" << std::endl;
        return Result(sp, false);
    }
    
    // 如果有空槽位，将任务放到任务队列中
    task_queue.emplace(sp);
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
    return Result(sp);
}

void ThreadPool::start(int thread_workers_init_size) {
    // 设置线程池的启动状态
    is_pool_running_ = true;

    // 记录初始线程个数
    thread_workers_init_size_ = thread_workers_init_size;
    thread_workers_curr_size_ = thread_workers_init_size;

    // 集中创建线程对象
    for (int i = 0; i < thread_workers_init_size; i++) {
        auto ptr = std::make_unique<Thread>(
                std::bind(&ThreadPool::thread_func, this, std::placeholders::_1));
        int thread_id = ptr->get_id();
        thread_workers.emplace(thread_id, std::move(ptr));
    }

    // 集中启动所有线程
    for (int i = 0; i < thread_workers_init_size; i++) {
        // 执行一个线程函数
        thread_workers[i]->start();
        // 记录初始空闲线程的数量
        thread_workers_idle_size_++;
    }
}

bool ThreadPool::check_running_state() const {
    return is_pool_running_;
}

void ThreadPool::thread_func(int thread_id) {
    // 死循环，执行工作的线程要一直待命
    auto last_time = std::chrono::high_resolution_clock().now();

    // 所有任务必须执行完成，线程池才可以回收所有线程资源
    while (true) {
        std::shared_ptr<Task> job;
        {
            // 获取锁
            std::cout << "tid: " << std::this_thread::get_id() << " waitting lock" << std::endl;
            std::unique_lock<std::mutex> lock(task_queue_mtx);
            std::cout << "tid: " << std::this_thread::get_id() << " got a lock" << std::endl;
            std::cout << "tid: " << std::this_thread::get_id()
                    << " trying get a job." << std::endl;

            while (task_queue.size() == 0) {
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
            job = task_queue.front();
            task_queue.pop();
            task_size_--;
            thread_workers_idle_size_--;
            std::cout << "tid: " << std::this_thread::get_id()
                    << " got a job." << std::endl;

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
            // 执行任务，把任务的返回值通过 set_value 方法给到 Result
            job->exec();
        }

        // 更新线程执行完任务的时间
        last_time = std::chrono::high_resolution_clock().now();
        // 成功执行完一个任务
        thread_workers_idle_size_++;
    }

}

//////////////// 线程方法实现 ////////////////

int Thread::generate_id_ = 0;

Thread::Thread(ThreadFunc func)
        : func_(func)
        , thread_id_(generate_id_++) {

}

Thread::~Thread() {

}

void Thread::start() {
    // 创建一个线程来执行一个线程函数
    // 线程对象是t，线程函数是 func, func 是真正的线程。
    std::thread t(func_, thread_id_);

    // 设置分离线程
    // t 本身是个局部变量，出作用域之后会析构，设置分离后，真正的线程（线程函数）可以存活。
    // 线程函数会等待任务到来并执行，其实际存在于线程容器中。
    t.detach();    
}

int Thread::get_id() const {
    return thread_id_;
}

//////////////////// Task 方法的实现
Task::Task() : result_(nullptr) {}

void Task::exec() {
    // 这里执行 run 函数时发生多态 
    if (result_ != nullptr) {
        result_->set_value(run());
    }
}

void Task::set_result(Result* res) {
    result_ = res;
}


//////////////////// Result 方法的实现
Result::Result(std::shared_ptr<Task> task, bool is_vaild) 
        : is_vaild_(is_vaild)
        , task_(task) {
    task_->set_result(this);
}

Any Result::get() {
    if (!is_vaild_) {
        return "";
    }

    // task 任务如果没有执行完，这里会阻塞用户的线程
    sem_.wait();
    return std::move(any_);
}

void Result::set_value(Any any) {
    // 存储 task 的返回值
    this->any_ = std::move(any);
    // 已经获取了任务的返回值，增加信号量资源
    sem_.post();
}