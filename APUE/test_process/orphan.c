/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：orphan.c
*   Author：leekaihua
*   Date：2024年05月19日
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// orphan process：父进程退出，但是子进程还在运行
int main() {
    pid_t pid = -1;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    // father process
    if (pid > 0) {
        printf("father process rest 1s and exit...\n");
        sleep(1);
        exit(0);
    }

    // sub process
    while (1) {
        printf("sub process work ppid: %d\n", getppid());
        sleep(1);
    }
    
    return 0;
}