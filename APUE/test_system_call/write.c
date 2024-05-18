/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：write.c
*   Author：leekaihua
*   Date：2024年05月17日
*   Brife：
*



*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = -1;
    int ret = -1;

    char* str = "hello itcast";

    fd = open("txt", O_WRONLY | O_CREAT, 0644);
    if (-1 == fd) {
        perror("open");
        return 1;
    }

    printf("fd=%d\n", fd);

    ret = write(fd, str, strlen(str));
    if (-1 == ret) {
        perror("write");
        return 1;
    }
    printf("write len: %d\n", ret);
    close(fd);
    
    return 0;
}
