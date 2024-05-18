/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：fcntl9.c
*   Author：leekaihua
*   Date：2024年05月18日
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

int main() {
    int fd = -1;
    int ret = -1;
    // 1 open a file
    fd = open("txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    printf("fd = %d\n", fd);

    // 2.获取文件状态标志
    ret = fcntl(fd, F_GETFL);
    if (ret == -1) {
        perror("fcntl");
        return 1;
    }
    if (ret & O_APPEND) {
        printf("before append\n");
    } else {
        printf("before not append\n");
    }

    // 3. 设置文件状态标记    
    ret = ret | O_APPEND;
    ret = fcntl(fd, F_SETFL, ret);
    if (ret == -1) {
        perror("fcntl");
        return 1;
    }

    // 4 获取文件状态标记
    ret = fcntl(fd, F_GETFL);
    if (ret == -1) {
        perror("fcntl");
        return 1;
    }
    if (ret & O_APPEND) {
        printf("before append\n");
    } else {
        printf("before not append\n");
    }
    // 5 close the file
    close(fd);

    return 0;
}