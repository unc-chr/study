/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_mmap.c
*   Author：leekaihua
*   Date：2024年05月20日
*   Brife：
*



*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

#include <sys/mman.h>

int main() {
    int fd = -1;
    int ret = -1;
    pid_t pid = -1;
    void* addr = NULL;

    // 1 以读写的方式打开一个文件
    fd = open("txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 2 将文件映射到内存
    addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    printf("mmap OK...\n");

    // 3 关闭文件
    close(fd);

    // 4 创建一个进程
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    // 子进程
    if (pid == 0) {
        memcpy(addr, "ABCDEFGHIJ", 10);
        // 这里不能exit，因为需要执行后续的munmap，断开存储映射
    } else {
    // 父进程
        // 等待子进程结束
        wait(NULL);
        printf("addr: %s\n", addr);
    }

    // 5 断开存储映射
    munmap(addr, 1024);

    return 0;
}