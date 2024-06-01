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
            int sum = 0;
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
    ThreadPool pool;
    pool.start(4);

    // 如何设计这里的 Result 机制？
    Result res = pool.submit_task(std::make_shared<MyTask>());
    // get 返回了一个 Any 类型，需要转回到具体的类型
    res.get().cast_<int>();
    pool.submit_task(std::make_shared<MyTask>());
    pool.submit_task(std::make_shared<MyTask>());
    pool.submit_task(std::make_shared<MyTask>());
    pool.submit_task(std::make_shared<MyTask>());
    pool.submit_task(std::make_shared<MyTask>());
    pool.submit_task(std::make_shared<MyTask>());
    pool.submit_task(std::make_shared<MyTask>());
    pool.submit_task(std::make_shared<MyTask>());
    std::cout << "press any key to continue..." << std::endl;
    getchar();
    return 0;
}