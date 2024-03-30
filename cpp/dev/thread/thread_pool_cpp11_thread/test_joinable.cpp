/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_joinable.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/
#include <iostream>
#include <thread>
void foo() {
    std::cout << "Thread started" << std::endl;
}
int main() {
    std::thread t(foo);
    if (t.joinable()) {
        t.join();
    }
    std::cout << "Thread joined" << std::endl;
    return 0;
}