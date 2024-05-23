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
#include <unistd.h>

int main() {
    int i = 0;
    while (1) {
        printf("do working %d\n", i);
        // 给自己发送一个信号
        if (i == 4) {
            // kill(getpid(), SIGTERM)
            raise(SIGTERM);
        }
        i++;
        sleep(1);
    }
    return 0;
}