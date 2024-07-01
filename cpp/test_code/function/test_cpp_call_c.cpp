/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_cpp_call_c.cpp
*   Author：leekaihua
*   Date：20240628
*   Brife：
*



*/
#include <iostream>

extern "C" {
    #include "sum.h"
}

int main() {
    int c = func(10, 20);
    std::cout << c << std::endl;
    return 0;
}