/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_async_future.cpp
*   Author：leekaihua
*   Date：2024年04月01日
*   Brife：
*



*/

#include <iostream>
#include <future>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void func1() {
    for (int i = 0; i < 50; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }
    cout << "func1" << endl;
}

void func2() {
    int i = 0;
    for (; i < 100; i++) {
        cout << "func2: " << i << endl;
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }
}

int main() {
    std::future<void > future_result = std::async(std::launch::async, func2);
    func1();
    return 0;
}