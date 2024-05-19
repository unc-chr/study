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

// zombie process：子进程结束了，父进程没有回收资源
int main() {
    pid_t pid = -1;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    // sub process
    if (pid == 0) {
        for (int i = 0; i < 5; i++) {
            printf("sub process do sth %d\n", i);
            sleep(1);
        }
        printf("sub process exit");
        exit(0);
    }

    // father process
    // getchar();
    sleep(100);
    printf("father process wake up...\n");
    
    return 0;
}