/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_bind.cpp
*   Author：leekaihua
*   Date：20240604
*   Brife：
*



*/

#include <functional>
#include <iostream>

// callback func, to show that std::function features
// 1 it could store a callable object
// 2 it could be delayed to anytime we want to call it, such as a function arg
void callback(int x, const std::function<void(int)>& func) {
    func(x);
}

void output1(int x) {
    if (!(x & 1)) {    // x is even
        std::cout << x << " ";
    }
}

void output2(int x) {
    if (!(x & 1)) {    // x is even
        std::cout << x + 2 << " ";
    }
}

int main() {
    std::function<void(int)> f1 = std::bind(output1, std::placeholders::_1);
    std::function<void(int)> f2 = std::bind(output2, std::placeholders::_1);
    // define return value type as auto is OK. Just as below.
    // That means we don't care which type that bind really return
    // auto f1 = std::bind(output1, std::placeholders::_1);
    // auto f2 = std::bind(output2, std::placeholders::_1);
    for (int i = 0; i < 10; i++) {
        // call f1 with i is ok.
        // f1(i);
        callback(i, f1);
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        // call f2 with i is ok.
        // f2(i);
        callback(i, f2);
    }
    std::cout << std::endl;

    return 0;
}