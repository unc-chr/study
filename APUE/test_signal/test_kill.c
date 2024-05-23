/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_kill.c
*   Author：leekaihua
*   Date：2024年05月20日
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = -1;

    // create sub process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
    // sub process
        while (1) {
            printf("child process do work...\n");
            sleep(1);
        }
        exit(0);
    } else {
    // father process
        sleep(3);
        printf("sub procerss time to exit...\n");
        // kill(pid, 9);
        kill(pid, 15);
        printf("father process time to exit...\n");
    }

    return 0;
}