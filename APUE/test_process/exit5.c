/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：exit5.c
*   Author：leekaihua
*   Date：2024年05月18日
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("hello world\n");
    _exit(0);
    // 等价于 return 0;
    // exit(0);
    // return 0;
}