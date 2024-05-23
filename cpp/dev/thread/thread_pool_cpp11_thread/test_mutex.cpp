/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_mutex.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
mutex mtx;

int shared_data = 0;
void func() {
    for (int i = 0; i < 100000; ++i) {
        // mtx.lock();
        shared_data++;
        // mtx.unlock();
    }
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(func);
    std::thread t2(func);
    t1.join();
    t2.join();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "shared_data = " << shared_data << std::endl;    
    std::chrono::duration<double> elapsed = end - start;
    std::cout << elapsed.count() << std::endl;
    return 0;
}