/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_dead_mutex.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx1;
mutex mtx2;

void func1() {
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mtx2.lock();
    cout << "func1" << endl;
    mtx1.unlock();
    mtx2.unlock();
}

void func2() {
    mtx2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mtx1.lock();
    cout << "func2" << endl;
    mtx1.unlock();
    mtx2.unlock();
}

int main() {
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();

    cout << "Done!" << endl;
    return 0;
}
