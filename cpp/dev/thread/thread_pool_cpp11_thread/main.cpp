/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：main.cpp
*   Author：leekaihua
*   Date：2024年03月28日
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

// todo 这个表达方式有问题
// void print_msg(string& msg) {
void print_msg(string msg) {
    cout << msg << endl;
    return;
}

int main() {
    // create thread
    // string msg1("Hello World");
    string msg1 = "Hello World";
    thread thread1(print_msg, msg1);
    // thread1.join();
    thread1.join();

    return 0;
}