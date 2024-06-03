/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_thread_pool.cpp
*   Author：leekaihua
*   Date：20240601
*   Brife：
*
*/

#include <iostream>
#include <chrono>
#include <thread>

#include "threadpool.h"

using ull = unsigned long long;

/*
有些场景，希望能够获取线程执行任务的返回值
其在任务未执行完毕期间，获取返回值的操作将会被阻塞。
例如：计算1+...+30000的和
thread1: 1+...+10000
thread2: 10901 + ... + 20000
thread3: 20001 + ... + 30000
main thread: 给每一个线程分配计算区间，并等待返回结果，合并最终结果
*/

class MyTask : public Task {
    public:
        MyTask(int begin, int end) : begin_(begin), end_(end) {}
        // 如何设计 run 函数的返回值，使其可以表示任何类型
        Any run() {
            std::cout << "tid: " << std::this_thread::get_id() 
                    << " begin" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            ull sum = 0;
            for (int i = begin_; i <= end_; i++) {
                sum += i;
            }
            std::cout << "tid: " << std::this_thread::get_id() 
                    << " end." << std::endl;
            return sum;
        }
    private:
        int begin_;
        int end_;
};

int main() {
    // ThreadPool 对象析构以后，需要把线程池相关的线程资源全部回收
    {
        ThreadPool pool;
        // 设置线程池的工作模式
        pool.set_mode(ThreadPoolMode::MODE_CACHED);
        // 启动线程池
        pool.start(4);

        // 如何设计这里的 Result 机制？
        Result res1 = pool.submit_task(std::make_shared<MyTask>(1, 100000000));
        Result res2 = pool.submit_task(std::make_shared<MyTask>(100000001, 200000000));
        Result res3 = pool.submit_task(std::make_shared<MyTask>(200000001, 300000000));
        Result res4 = pool.submit_task(std::make_shared<MyTask>(300000001, 400000000));
        Result res5 = pool.submit_task(std::make_shared<MyTask>(400000001, 500000000));
        Result res6 = pool.submit_task(std::make_shared<MyTask>(500000001, 600000000));
        // get 返回了一个 Any 类型，需要转回到具体的类型
        ull sum1 = res1.get().cast_<ull>();
        std::cout << sum1 << std::endl;
        // pool.submit_task(std::make_shared<MyTask>());
        // pool.submit_task(std::make_shared<MyTask>());
        // pool.submit_task(std::make_shared<MyTask>());
        // pool.submit_task(std::make_shared<MyTask>());
        // pool.submit_task(std::make_shared<MyTask>());
        // pool.submit_task(std::make_shared<MyTask>());
        // pool.submit_task(std::make_shared<MyTask>());
        // pool.submit_task(std::make_shared<MyTask>());
    }
    // ThreadPool 对象析构以后，怎么把线程池相关的线程资源全部回收
    std::cout << "press any key to continue..." << std::endl;
    getchar();
    return 0;
}