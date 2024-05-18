/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：getcwd1.c
*   Author：leekaihua
*   Date：2024年05月18日
*   Brife：
*



*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 128

int main() {
    char buf[SIZE];
    int ret = -1;
    // 1 get workpath of current process
    memset(buf, 0, SIZE);
    if (NULL == getcwd(buf, SIZE)) {
        perror("getcwd");
        return 1;
    }
    printf("buf: %s\n", buf);

    // 2 change workpath of current process
    ret = chdir("/home/lkh/study/APUE/test_system_call/test");
    if (ret == -1) {
        perror("chdir");
        return 1;
    }

    // 3 get workpath of current process
    memset(buf, 0, SIZE);
    if (NULL == getcwd(buf, SIZE)) {
        perror("getcwd");
        return 1;
    }
    printf("buf: %s\n", buf);

    return 0;
}