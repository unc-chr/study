/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_sigset.c
*   Author：leekaihua
*   Date：2024年05月20日
*   Brife：
*



*/

#include <stdio.h>
#include <signal.h>

void show_set(sigset_t* s) {

    for (int i = 1; i < 32; i++) {
        if (sigismember(s, i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    putchar('\n');
}

// 信号集处理函数
int main() {
    int i = 0;

    // 信号集集合
    sigset_t set;

    // 清空集合
    sigemptyset(&set);
    show_set(&set);

    // 将所有的信号加入到 set 集合中
    sigfillset(&set);
    show_set(&set);

    // 将信号2/3从信号集中移除
    sigdelset(&set, SIGINT);
    sigdelset(&set, SIGQUIT);
    show_set(&set);

    // 将信号2添加到集合中
    sigaddset(&set, SIGINT);
    show_set(&set);

    return 0;
}