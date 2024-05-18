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

#define SIZE 128
int main() {
    int fd = -1;
    int ret = -1;

    char buf[SIZE];
    // open file with read only mode
    fd = open("txt", O_RDONLY);
    if (-1 == fd) {
        perror("open");
        return 1;
    }

    printf("fd=%d\n", fd);

    memset(buf, 0, SIZE);
    // read file
    ret = read(fd, buf, SIZE);
    if (-1 == ret) {
        perror("read");
        return 1;
    }
    printf("read len: %d %s\n", ret, buf);
    // close file
    close(fd);
    
    return 0;
}
