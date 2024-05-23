/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_thread.cpp
*   Author：leekaihua
*   Date：2024年04月28日
*   Brife：
*



*/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <chrono>

std::mutex mx1;
std::mutex mx2;

void func1(const std::string& content) {
    std::cout << content << std::endl;
}

static int count1 = 0;
static int count2 = 0;
void add1() {
    for (int i = 0; i < 100000; i++) {
        mx1.lock();
        count1++;
        mx.unlock();
    }
}

void add2() {
    for (int i = 0; i < 100000; i++) {
        mx.lock();
        count2++;
        mx.unlock();
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(add);
    std::thread t2(add);
    t1.join();
    t2.join();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << count << std::endl;
    std::cout << elapsed.count() << std::endl;

    return 0;
}