/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：talkA.c
*   Author：leekaihua
*   Date：2024年05月20日
*   Brife：
*



*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define SIZE 128

// 先写后读
// 以只读的方式打开管道 a2b
// 以只写的方式打开管道 b2a
int main() {
    int fdr = -1;
    int fdw = -1;
    int ret = -1;

    char buf[SIZE];

    // 以只写的方式打开管道 b2a
    fdw = open("fifo_b2a", O_WRONLY);
    if (fdw == -1) {
        perror("open");
        return 1;
    }
    printf("open fifo_b2a with write-only mode...\n");

    // 以只读的方式打开管道 a2b
    fdr = open("fifo_a2b", O_RDONLY);
    if (fdr == -1) {
        perror("open");
        return 1;
    }
    printf("open fifo_a2b with read-only mode...\n");

    // 循环读写，先写后读
    while (1) {
        // 写管道
        memset(buf, 0, SIZE);
        fgets(buf, SIZE, stdin);
        // 去掉最后一个换行符
        if ('\n' == buf[strlen(buf) - 1]) {
            buf[strlen(buf) - 1] = '\0';
        }
        ret = write(fdw, buf, strlen(buf));
        if (ret <= 0) {
            perror("write");
            break;
        }
        printf("B write to A: %s\n", buf);

        // 读管道
        memset(buf, 0, SIZE);
        ret = read(fdr, buf, SIZE);
        if (ret <= 0) {
            perror("read");
            break;
        }
        printf("B read from A : %s\n", buf);
    }

    // 关闭文件描述符
    close(fdr);
    close(fdw);

    return 0;
}