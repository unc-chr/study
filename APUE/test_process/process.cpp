/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：process.cpp
*   Author：leekaihua
*   Date：2024年05月18日
*   Brife：
*



*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = -1;
    // get pid of current process
    pid = getpid();
    printf("process id: %d\n", pid);
    pid = getppid();
    printf("father process id: %d\n", pid);
    pid = getpgid(getpid());
    printf("process group id: %d\n", pid);
    return 0;
}