/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：fork3.cpp
*   Author：leekaihua
*   Date：2024年05月18日
*   Brife： 父子进程的地址空间
*



*/
#include <stdio.h>
#include <unistd.h>

// global variable
int num = 100;

int main() {
    int var = 88;
    pid_t pid = -1;
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        // sub process
        sleep(1);
        printf("sub proc after sleep var = %d num=%d\n", var, num);
    } else {
        // father process
        printf("father proc before var = %d num=%d\n", var, num);
        // 写时拷贝，所以父子进程的 var 是不同的内存
        var++;
        num++;
        printf("father proc after var = %d num=%d\n", var, num);
    }
    return 0;
}