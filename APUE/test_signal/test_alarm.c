/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_alarm.c
*   Author：leekaihua
*   Date：2024年05月20日
*   Brife：
*



*/
#include <stdio.h>
#include <unistd.h>

int main() {
    unsigned int ret = 0;

    // 设置5s之后超时
    ret = alarm(5);
    printf("last alarm remaining seconds: %u\n", ret);
    sleep(2);
    ret = alarm(4);
    printf("last alarm remaining seconds: %u\n", ret);

    printf("press any key continue...\n");
    getchar();

    return 0;
}