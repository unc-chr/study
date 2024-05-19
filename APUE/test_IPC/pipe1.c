/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：pipe1.c
*   Author：leekaihua
*   Date：2024年05月19日
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// 创建无名管道
int main() {
    int fd[2];
    int ret = -1;
    ret = pipe(fd);
    if (ret == -1) {
        perror("pipe");
        return 1;
    }
    printf("fd[0]:%d fd[1]:%d\n", fd[0], fd[1]);
    close(fd[0]);
    close(fd[1]);

    return 0;
}