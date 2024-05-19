/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_mkfifo.c
*   Author：leekaihua
*   Date：2024年05月19日
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// 通过 mkfifo 函数创建一个管道文件
int main() {
    int ret = -1;
    ret = mkfifo("./fifo", 0644);
    if (ret == -1) {
        perror("mkfifo");
        return 1;
    }
    printf("make named pipe successfully.\n");
    return 0;
}