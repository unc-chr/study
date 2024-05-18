/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2023年03月22日
*   Brife：
*



*/

#include <iostream>

// 这个函数必须在 模板函数之前定义，否则会报错，说 sum_value 模板参数推导失败。
long double sum_value() {
    return 0.0;
}

template<typename T, typename... Args>
long double sum_value(T value, Args... args) {
    return value + sum_value(args...);
}

int main() {
    using namespace std;
    long double result = sum_value(1, 2, 3.3, 4, 'c', 'g', 'f'); 
    cout << "result: " << result << endl;

    return 0;
}

