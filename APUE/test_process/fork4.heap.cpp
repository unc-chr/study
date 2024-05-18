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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// global variable
int num = 100;

int main() {
    int var = 88;
    pid_t pid = -1;
    int* p = nullptr;

    // get memory space in heap area
    p = static_cast<int*>(malloc(sizeof(int)));
    if (p == nullptr) {
        printf("malloc failed...\n");
        return 1;
    }
    memset(p, 0, sizeof(int));
    *p = 200;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        // sub process
        sleep(1);
        printf("sub proc after sleep var = %d num=%d *p=%d\n", var, num, *p);
        free(p);
        p = nullptr;
    } else {
        // father process
        printf("father proc before var = %d num=%d *p=%d\n", var, num, *p);
        // 写时拷贝，所以父子进程的 var 是不同的内存
        var++;
        num++;
        (*p)++;
        printf("father proc after var = %d num=%d *p=%d\n", var, num, *p);
        free(p);
        p = nullptr;
    }
    return 0;
}