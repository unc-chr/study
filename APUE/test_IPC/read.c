/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：read.c
*   Author：leekaihua
*   Date：2024年05月19日
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 128

// 读管道
int main() {
    int fd = -1;
    int ret = -1;
    char buf[SIZE];

    // 1 以只读的方式打开管道
    fd = open("fifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    printf("open a named pipe with read only mode...\n");

    // 2 循环读管道
    while (1) {
        memset(buf, 0, SIZE);
        ret = read(fd, buf, SIZE);
        if (ret <= 0) {
            perror("read");
            break;
        }
        printf("buf:%s\n", buf);
    }

    // 3 关闭管道
    close(fd);
    return 0;
}