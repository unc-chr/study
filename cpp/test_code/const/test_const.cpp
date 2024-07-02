/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_const.cpp
*   Author：leekaihua
*   Date：20240628
*   Brife：
*



*/
#include <stdio.h>

int main() {
    int b = 20;
    const int a = b;
    int array[a] = {};

    int* p = (int*)&a;
    *p = 30;

    printf("%d %d %d\n", a, *p, *(&a));

    return 0;
}