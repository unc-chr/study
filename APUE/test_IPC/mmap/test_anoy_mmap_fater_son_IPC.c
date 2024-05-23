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

// 使用匿名映射实现父子进程间通信。
int main() {
    int fd = -1;
    int ret = -1;
    pid_t pid = -1;
    void* addr = NULL;

    // 1 创建匿名映射
    addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // 2 创建一个进程
    pid = fork();
    if (pid == -1) {
        perror("fork");
        munmap(addr, 4096);
        return 1;
    }

    // 3 父子进程通信
    // 子进程
    if (pid == 0) {
        memcpy(addr, "1234567890", 10);
        // 这里不能exit，因为需要执行后续的munmap，断开存储映射
    } else {
    // 父进程
        // 等待子进程结束
        wait(NULL);
        printf("parent process: %s\n", addr);
    }

    // 4 断开存储映射
    munmap(addr, 4096);

    return 0;
}