/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_func.cpp
*   Author：leekaihua
*   Date：20240624
*   Brife：
*



*/

#include <iostream>

int sum(int a, int b) {
    int temp = 0;
    temp = a + b;
    return temp;
}

int main() {
    int a = 10;
    int b = 20;

    int ret = sum(a, b);
    std::cout << "ret: " << ret << std::endl;
    return 0;
}