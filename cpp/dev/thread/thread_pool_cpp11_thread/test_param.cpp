/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_param.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/
#include <iostream>
#include <string>
#include <thread>

using std::cout;
using std::endl;
using std::string;
using std::thread;

void print_message(const string& message) {    
    cout << message << endl;
}

void increment(int& x) {
    ++x;
}

int main() {
    string message = "Hello, world!";
    thread t(print_message, message);
    t.join();
    int x = 0;
    thread t2(increment, std::ref(x));
    t2.join();
    cout << x << endl;

    return 0;
}