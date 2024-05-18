/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：dup8.c
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

int main() {
    int fd = -1;
    int new_fd = -1;
    int new_fd2 = 5;
    // 1 open file
    fd = open("txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    printf("fd = %d\n", fd);

    // copy a file descriptor
    new_fd = dup(fd);
    if (new_fd == -1) {
        perror("dup");
        return 1;
    }
    printf("fd = %d\n", new_fd);
    // copy a file descriptor use dup2 function
    new_fd2 = dup2(fd, new_fd2);
    if (new_fd == -1) {
        perror("dup");
        return 1;
    }
    printf("new_fd2 = %d\n", new_fd2);

    // 2 operate file
    write(fd, "ABCDEFG", 7);
    write(new_fd, "1234567", 7);
    write(new_fd2, "abcdefg", 7);

    // 3 close file descriptor
    close(fd);
    close(new_fd);
    close(new_fd2);

    return 0;
}