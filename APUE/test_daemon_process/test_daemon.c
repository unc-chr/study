/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_daemon.c
*   Author：leekaihua
*   Date：20240520
*   Brife：
*



*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define SIZE 64
// create daemon process
int main() {
    pid_t pid = -1;
    int ret = -1;
    time_t t = -1;
    struct tm* pt = NULL;
    char file_name[SIZE];

    // 1 create child process, father process exit
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        exit(0);
    }

    // 2 create new session
    // child process ha no controlling terminal
    pid = setsid();
    if (-1 == pid) {
        perror("setsid");
        return 1;
    }

    // 3 change current working directory to root
    ret = chdir("/");
    if (-1 == ret) {
        perror("chdir");
        return 1;
    }

    // 4 set unmask
    umask(0);

    // 5 close file descriptor
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // 6 do daemon process work
    // append current time to /tmp/txt.log each 1s
    while (1) {
        // get time
        t = time(NULL);
        if (-1 == t) {
            perror("time");
            return 1;
        }
        // convert to time
        pt = localtime(&t);
        if (NULL == pt) {
            printf("localtime failed!");
            return 1;
        }
        // convert time to file name
        memset(file_name, 0, SIZE);
        sprintf(file_name, "touch /home/lkh/study/APUE/test_daemon_process/%d%02d%02d%02d%02d%02d.log", 
                                    pt->tm_year + 1900, 
                                    pt->tm_mon + 1,
                                    pt->tm_mday,
                                    pt->tm_hour,
                                    pt->tm_min,
                                    pt->tm_sec);

        // create a file with specific file name
        printf("file_name: %s\n", file_name);
        system(file_name);
        sleep(2);
    }
    return 0;
}