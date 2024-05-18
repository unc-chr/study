/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：lseek5.c
*   Author：leekaihua
*   Date：2024年05月18日
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

#define SIZE 128

int main() {
    int fd = -1;
    int ret = -1;
    char buf[SIZE];
    // 1 open file
    fd = open("txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    printf("fd=%d\n", fd);
    // 2 lseek operation
    write(fd, "ABCDEFG", 7);

    // offset 32 Byte from beginning of file
    ret = lseek(fd, 32, SEEK_SET);
    write(fd, "0123456789", 10);

    lseek(fd, 0, SEEK_SET);
    memset(buf, 0, SIZE);
    read(fd, buf, SIZE);
    printf("read ret:%d buf: %s\n", ret, buf);
    // 3 close file
    close(fd);
    return 0;
}