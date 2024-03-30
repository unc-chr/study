/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_detach.cpp
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
    std::thread t(print_message, "Thread 1");
    t.detach();
    std::cout << "Thread detached" << std::endl;
    return 0;
}