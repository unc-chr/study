/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：open2.c
*   Author：leekaihua
*   Date：2024年05月17日
*   Brife：
*



*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = -1;
    // fd = open("txt", O_RDONLY);
    // fd = open("txt", O_WRONLY | O_CREAT, 0644);
    fd = open("txt", O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("fd=%d\n", fd);

    close(fd);
    return 0;
}
