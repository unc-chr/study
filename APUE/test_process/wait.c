/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：wait.c
*   Author：leekaihua
*   Date：2024年05月19日
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// wait sub process exit
int main() {
    pid_t pid = -1;
    int ret = -1;
    int status = 0;

    // create sub process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        for (int i = 0; i < 5; i++) {
            printf("child process %d do thing %d\n", getpid(), i + 1);
            sleep(1);
        }
        exit(10);
    }

    // father process
    printf("father process is waitting for sub process exiting, recycle resource\n");
    // father process blocked, and wait sub process exit
    // ret = wait(&status);
    // 等价于 wait
    // ret = waitpid(-1, &status, 0);
    // 第三个参数表示不阻塞
    ret = waitpid(-1, &status, WNOHANG);
    if (ret == -1) {
        perror("wait");
        return 1;
    }
    printf("father process recycle sub process resource done.\n");
    if (WIFEXITED(status)) {
        // 正常退出
        printf("sub process exit code: %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        // 运行的时候，kill -9 pid
        printf("sub process killed by status: %d\n", WTERMSIG(status));
    } else if (WIFSTOPPED(status)) {
        // 运行的时候，kill -19 pid 实现进程暂停
        // kill -18 pid 恢复运行
        printf("sub process paused by status: %d\n", WSTOPSIG(status));
    }

    return 0;
}