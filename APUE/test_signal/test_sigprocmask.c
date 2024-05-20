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
    // 信号集
    sigset_t set;
    sigset_t old;

    int ret = -1;

    // ctrl + c
    signal(SIGINT, func1);

    // ctrl + '\'
    signal(SIGQUIT, func2);

    printf("press any key block signal 2..\n");
    getchar();
    sigemptyset(&set);
    sigemptyset(&old);
    sigaddset(&set, SIGINT);
    // 设置屏蔽编号为2的信号
    ret = sigprocmask(SIG_BLOCK, &set, &old);
    if (-1 == ret) {
        perror("sigprocmask");
        return 1;
    }
    printf("set signal 2 successfully...\n");

    printf("press any key unblock signal 2...\n");
    getchar();
    // 将屏蔽信号机设置为原来的集合
    ret = sigprocmask(SIG_SETMASK, &old, NULL);
    if (-1 == ret) {
        perror("sigprocmask");
        return 1;
    }
    printf("press any key exit ...\n");
    getchar();

    return 0;
}