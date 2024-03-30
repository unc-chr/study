/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_multi_thread_print.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

using std::cout;
using std::endl;
using std::string;
using std::thread;

void print_message(int seq) {
    for (int i = 0; i < 10; i++) {
        cout << seq << ": " << i << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    thread t1(print_message, 1);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    thread t2(print_message, 2);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    thread t3(print_message, 3);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    t1.join();
    t2.join();
    t3.join();
    cout << "thread execute done." << endl;

    return 0;
}