/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p3.openai.cpp
*   Author：leekaihua
*   Date：2023年03月22日
*   Brife：
*



*/

#include <iostream>
#include <cctype>

template <typename T, typename... Args>
long double sum_value(T value, Args... args) {
    return value + sum_value(args...);
}

long double sum_value() {
    return 0.0;
}

int main() {
    using namespace std;
    long double result = sum_value(1, 2, 3.3, 4, 'c', 'g', 'f'); 
    cout << "result: " << result << endl;

    return 0;
}
