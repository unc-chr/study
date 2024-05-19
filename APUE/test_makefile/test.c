/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test.c
*   Author：leekaihua
*   Date：2024年05月17日
*   Brife：
*



*/
#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main() {
    int x = 15;
    int y = 5;
    printf("x + y = %d\n", add(x, y));
    printf("x - y = %d\n", sub(x, y));
    printf("x * y = %d\n", mul(x, y));
    printf("x / y = %d\n", div(x, y));
    return 0;
}
