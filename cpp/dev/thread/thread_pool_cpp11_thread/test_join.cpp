/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_join.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/

#include <iostream>
#include <thread>
void print_message(const std::string& message) {
    std::cout << message << std::endl;
}

int main() {
    std::thread t1(print_message, "Thread 1");
    std::thread t2(print_message, "Thread 2");
    t1.join();
    t2.join();
    std::cout << "All threads joined" << std::endl;

    return 0;
}