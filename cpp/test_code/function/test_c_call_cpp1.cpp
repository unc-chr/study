/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_c_call_cpp1.cpp
*   Author：leekaihua
*   Date：20240628
*   Brife：
*



*/
#include <stdio.h>

#include "func.h"

int main() {
    int ret = func(10, 20);
    printf("ret: %d\n", ret);
    return 0;
}