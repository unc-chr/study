/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_sigaction.c
*   Author：leekaihua
*   Date：2024年05月20日
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void fun(int signo) {
    printf("捕捉到信号 %d\n", signo);
}

// 新的信号处理函数
void fun1(int signo, siginfo_t* info, void* content) {
    printf("捕捉到信号 %d\n", signo);
}

int main() {
    int ret = -1;

#if 0
    struct sigaction act;
    // 使用旧的信号处理函数指针
    act.sa_handler = fun;
    act.sa_flags = 0;

#else
    struct sigaction act;
    // 使用新的信号处理函数指针
    act.sa_sigaction = fun1;
    // 标志指定使用新的信号处理函数指针
    act.sa_flags = SA_SIGINFO;
#endif
    // 信号注册
    ret = sigaction(SIGINT, &act, NULL);
    if (-1 == ret) {
        perror("sigaction");
        return 1;
    }

    printf("按下任意键继续...\n");
    while (1) {
        getchar();
    }

    return 0;
}