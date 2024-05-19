/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：execv.c
*   Author：leekaihua
*   Date：2024年05月19日
*   Brife：
*



*/

#if 0
        int execl(const char *path, const char *arg, ...);
        int execlp(const char *file, const char *arg, ...);
        int execle(const char *path, const char *arg,
                ..., char * const envp[]);
        int execv(const char *path, char *const argv[]);
        int execvp(const char *file, char *const argv[]);
        int execvpe(const char *file, char *const argv[],
                char *const envp[]);
#endif

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>

int main() {
    char* argv[] = {"ls", "-l", "/home/lkh", NULL};
    char* envp[] = {"ADDR=BEIJING", NULL};

    printf("hello world!\n");

    // execv("/bin/ls", argv);
    // execvp("ls", argv);
    execvpe("ls", argv, envp);

    printf("hello itcast\n");
    return 0;
}