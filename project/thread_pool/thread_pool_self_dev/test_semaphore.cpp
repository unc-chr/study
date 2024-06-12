/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_semaphore.cpp
*   Author：leekaihua
*   Date：20240612
*   Brife：
*



*/
#include <iostream>
#include <chrono>
#include <string>
#include <thread>

#include "semaphore.h"

// 对于这个测试用例，信号量的初始值必须为1。
// 必须让一个 printer 先运行起来。
Semaphore sem(1);

void printer(const std::string& str) {
    for(size_t i = 0; i < str.size(); i++) {
        std::cout << str[i] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << std::endl;
}

void printer1() {
    std::string str = "hello";
    sem.wait();
    printer(str);
    sem.post();
}

void printer2() {
    std::string str = "world";
    sem.wait();
    printer(str);
    sem.post();
}

int main() {
    std::thread t1(printer1);
    std::thread t2(printer2);
    t1.join();
    t2.join();
    return 0;
}