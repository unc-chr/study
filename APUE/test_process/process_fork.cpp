/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：process_fork.cpp
*   Author：leekaihua
*   Date：2024年05月18日
*   Brife：
*



*/
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = -1;
    // create sub process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        // sub process
        printf("sub process pid:%d father process pid:%d\n", getpid(), getppid());
    } else {
    // father process
        printf("father process pid:%d sub process pid:%d\n", getpid(), pid);
    }
    printf("hello world pid: %d\n", getpid());
    return 0;
}