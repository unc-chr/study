/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：tcp_server_mul_process.c
*   Author：leekaihua
*   Date：20240524
*   Brife：multi process server, communicate with multi clients
*



*/

#include "../wrapped_func/wrap_err.h"
#include "../wrapped_func/wrap_sys.h"
#include "../wrapped_func/wrap_sig.h"

#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 144
#define EXIT_CMD "exit\n"

int cmp(char* src, char* dest) {

}

void do_work(int fd) {
    char buf_read[SIZE];
    char buf_write[SIZE];
    int ret = -1;
    while (1) {
        // reading from client
        printf("reading from client:\n");
        ret = Read(fd, buf_read, SIZE);
        if (strcmp(buf_read, EXIT_CMD, strlen(EXIT_CMD)) == 0) {
            break;
        }
        printf("%s\n", buf_read);
        // writing to client
        memset(buf_write, 0, sizeof(buf_write));
        sprintf(buf_write, "confirm received: %s", buf_read);
        ret = Write(fd, buf_write, SIZE);
        printf("sending to client: %s", buf_write);
    }
}

void free_process(int sig) {
    pid_t pid;
    while (1) {
        pid = waitpid(-1, NULL, WNOHANG);
        if (pid <= 0) {
            break;
        } else {
            printf("child pid: %d\n", pid);
        }
    }
}

int main() {
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);
    sigprocmask(SIG_BLOCK, &set, NULL);

    int ret = -1;

    // create socket
    int lfd = Socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket\n");

    // bind
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    ret = Inet_pton(AF_INET, "192.168.58.130", &addr.sin_addr.s_addr);
    ret = Bind(lfd, (struct sockaddr*)&addr, sizeof(addr));
    printf("Bind\n");

    // listen
    ret = Listen(lfd, 25);
    printf("Listen\n");

    // accept incoming connect, fork child process and do work
    struct sockaddr_in cli_addr;
    socklen_t len = sizeof(cli_addr);
    char ip[16] = "";
    while (1) {
        // accept
        int cfd = Accept(lfd, (struct sockaddr*)&cli_addr, &len);
        printf("new client ip=%s port=%d\n", 
                inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, 16),
                ntohs(cli_addr.sin_port));
        // fork
        pid_t pid = fork();
        if (-1 == pid) {
            Perror("fork error");
        }
        if (pid == 0) {
            // child process
            printf("curr pid: %d\n", getpid());
            // close lfd, child process doesn't need it
            close(lfd);
            do_work(cfd);
        } else {
            // parent process
            // close cfd in parent process, keep lfd only
            // and keep listening
            close(cfd);
            // if child process end, recycle resource
            struct sigaction act;
            act.sa_flags = 0;
            act.sa_handler = free_process;
            sigemptyset(&act.sa_mask);
            sigaction(SIGCHLD, &act, NULL);
            sigprocmask(SIG_UNBLOCK, &set, NULL);
        }
    }

    return 0;

}