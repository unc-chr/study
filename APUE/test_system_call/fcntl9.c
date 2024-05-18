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
    int new_fd = -1;
    // 1 open a file
    fd = open("txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    printf("fd = %d\n", fd);

    // 2 copy a file descriptor
    new_fd = fcntl(fd, F_DUPFD, 10);
    if (new_fd == -1) {
        perror("fcntl");
        return 1;
    }
    printf("new_fd = %d\n", new_fd);

    // 3 write something
    write(fd, "123456789", 9);
    write(new_fd, "abcdefgh", 8);

    // 4 close file
    close(fd);
    close(new_fd);

    return 0;
}