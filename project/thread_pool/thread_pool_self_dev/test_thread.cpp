/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_thread.cpp
*   Author：leekaihua
*   Date：20240612
*   Brife：
*



*/

#include <functional>
#include <iostream>
#include <chrono>

#include "thread.h"

void fun(int num) {
    std::cout << "output: " << num << std::endl;
}

int main() {
    std::function<void(int)> func = std::bind(fun, std::placeholders::_1);
    Thread* t1 = new Thread(func);
    Thread* t2 = new Thread(func);
    std::cout << "t1 thread id: " << t1->get_id() << std::endl;
    std::cout << "t2 thread id: " << t2->get_id() << std::endl;
    t1->start();
    t2->start();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}