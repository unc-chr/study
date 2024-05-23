/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_atomic.cpp
*   Author：leekaihua
*   Date：2024年04月01日
*   Brife：
*



*/
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> shared_data;

void func() {
    for (int i = 0; i < 10000; i++) {
        shared_data++;
        // shared_data = shared_data + 1;
    }
}

int main() {
    std::thread t1(func);
    std::thread t2(func);
    t1.join();
    t2.join();
    std::cout << "shared_data = " << shared_data << std::endl;

    return 0;
}