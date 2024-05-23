/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_setitimer.c
*   Author：leekaihua
*   Date：2024年05月20日
*   Brife：
*



*/
#include <stdio.h>
#include <sys/time.h>

int main() {
    int ret = -1;
    struct itimerval tmo;
    // 第一次触发时间
    tmo.it_value.tv_sec = 3;
    tmo.it_value.tv_usec = 0;

    // 触发周期
    tmo.it_interval.tv_sec = 2;
    tmo.it_interval.tv_usec = 0;

    ret = setitimer(ITIMER_REAL, &tmo, NULL);
    if (-1 == ret) {
        perror("setitimer");
        return 1;
    }

    printf("press any key to continue...\n");
    getchar();

    return 0;
}