/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：variadic2.cpp
*   Author：leekaihua
*   Date：2024年03月31日
*   Brife：
*



*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 先定义接受一个参数的模板函数，以供可变参数模板函数递归调用
template <typename T>
void show_list(T value) {
    cout << value << endl;
}

template <typename T, typename... Args>
void show_list(T value, Args... args) {
    cout << value << ", ";
    // 这里展开参数包，实现递归调用
    show_list(args...);
}

int main() {
    string msg("this is end!");
    show_list(1, 2.3, "hello world", msg);
    return 0;
}