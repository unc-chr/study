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

int fun() {
    int i = 0;
    for (int i = 0; i < 10; i++) {
        printf("fun==>i=%d\n", i);
    }
}

int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    fun();

    printf("hello world!\n");
    return 0;
}
