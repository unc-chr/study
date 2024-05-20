/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_raise.c
*   Author：leekaihua
*   Date：2024年05月20日
*   Brife：
*



*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i = 1;
    while (1) {
        printf("do working... %d\n", i);
        if (4 == i) {
            abort();
        }
        i++;
        sleep(1);
    }
    return 0;
}