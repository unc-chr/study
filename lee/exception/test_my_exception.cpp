/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_my_except.cpp
*   Author：leekaihua
*   Date：20240701
*   Brife：
*



*/
#include "my_exception.h"
using lee::exception::out_of_vector_range;

int main() {
    throw out_of_vector_range(16, 12);
    return 0;
}
