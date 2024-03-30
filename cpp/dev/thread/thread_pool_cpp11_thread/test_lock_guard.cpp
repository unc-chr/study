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

using namespace std;
mutex mtx;

int shared_data = 0;
void func() {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> lg(mtx);
        shared_data++;
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