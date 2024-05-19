/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：pipe_fork_IPC.c
*   Author：leekaihua
*   Date：2024年05月19日
*   Brife：
*       父子进程使用无名管道实现通信
*       父进程写管道。
*       子进程读管道。
*
*/

#define SIZE 64

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int ret = -1;
    pid_t pid = -1;
    int fds[2];
    char buf[SIZE];

    // 1 创建无名管道
    ret = pipe(fds);
    if (ret == -1) {
        perror("pipe");
        return 1;
    }

    // 2 创建子进程
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    // 子进程
    if (pid == 0) {
        // 子进程读，所以关闭写端
        close(fds[1]);

        memset(buf, 0, SIZE);
        ret = read(fds[0], buf, SIZE);
        if (ret < 0) {
            perror("read");
            exit(-1);
        }
        printf("child process buf: %s\n", buf);

        // 操作完成，关闭读端
        close(fds[0]);
        // 进程退出
        exit(0);
    }
    // 父进程 写管道
    // 关闭读端
    close(fds[0]);

    ret = write(fds[1], "ABCDEFGHIJ", 10);
    if (ret < 0) {
        perror("write");
        return 1;
    }
    printf("parent process write len: %d\n", ret);
    // 关闭写端
    close(fds[1]);
    return 0;
}