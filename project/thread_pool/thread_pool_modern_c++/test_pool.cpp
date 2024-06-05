/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：20240604
*   Brife：
*



*/

#include <chrono>
#include <functional>
#include <future>
#include <iostream>
#include <thread>

#include "threadpool.h"

int sum1(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

int sum2(int a, int b, int c) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b + c;
}

int main() {
    ThreadPool pool;
    // pool.set_mode(ThreadPoolMode::MODE_CACHED);
    pool.start(2);
    std::future<int> r1 = pool.submit_task(sum1, 1, 2);
    std::future<int> r2 = pool.submit_task(sum2, 1, 2, 4);
    std::future<int> r3 = pool.submit_task(sum1, 1, 3);
    std::future<int> r4 = pool.submit_task(sum1, 4, 2);
    std::future<int> r5 = pool.submit_task(sum1, 4, 1);
    std::future<int> r6 = pool.submit_task(sum1, 4, 5);
    std::future<int> r7 = pool.submit_task([](int b, int e)->int {
        int sum = 0;
        for (int i = b; i < e; i++) {
            sum += i;
        }
        return sum;
    }, 1, 100);
    std::cout << r1.get() << std::endl;
    std::cout << r2.get() << std::endl;
    std::cout << r3.get() << std::endl;
    std::cout << r4.get() << std::endl;
    std::cout << r5.get() << std::endl;
    std::cout << r6.get() << std::endl;
    std::cout << r7.get() << std::endl;
    // std::packaged_task<int(int, int)> task(sum1);
    // // future <=> Result, 
    // // future wrapper is similar to self-defined Result class
    // std::future<int> res = task.get_future();
    // task(10, 20);
    // std::cout << res.get() << std::endl;

    return 0;
}