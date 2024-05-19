/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：write.c
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

// 写命名管道
int main() {
    int i = 0;
    int ret = -1;
    int fd = -1;
    char buf[SIZE];

    // 1 以只写方式打开一个管道
    fd = open("fifo", O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    printf("open a named pipe with write only mode\n");

    // 2 写管道
    while (1) {
        memset(buf, 0, SIZE);
        sprintf(buf, "hello itcast %d", i++);
        ret = write(fd, buf, strlen(buf));
        if (ret <= 0) {
            perror("write");
            break;
        }
        printf("write to fifo:%d\n", ret);
        sleep(1);
    }

    // 3 关闭管道
    close(fd);
    return 0;
}