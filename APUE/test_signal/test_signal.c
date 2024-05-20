/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_signal.c
*   Author：leekaihua
*   Date：2024年05月20日
*   Brife：
*



*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// 信号处理函数1
void func1(int signum) {
    printf("caught signal: %d\n", signum);
}

// 信号处理函数1
void func2(int signum) {
    printf("caught signal: %d\n", signum);
}

int main() {
    // ctrl + c
    signal(SIGINT, func1);

    // ctrl + '\'
    signal(SIGQUIT, func2);

    while (1) {
        sleep(1);
    }

    return 0;
}