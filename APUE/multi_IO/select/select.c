/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：select.c
*   Author：leekaihua
*   Date：20240526
*   Brife：
*



*/

#include "../../wrapped_func/wrap_sig.h"
#include "../../wrapped_func/wrap_sys.h"

#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8888
#define IP "192.168.58.130"
#define SIZE 1024

int main() {
    // create socket and bind
    int lfd = tcp4_bind(PORT, IP);
    if (-1 == lfd) {
        return -1;
    }
    printf("bind4tcp\n");
    // listen
    int ret = Listen(lfd, 128);
    if (-1 == ret) {
        return -1;
    }
    printf("Listen\n");
    // accept

    int max_fd = lfd;
    fd_set old_fds_set;
    fd_set rst_fds_set;
    FD_ZERO(&old_fds_set);
    FD_ZERO(&rst_fds_set);
    FD_SET(lfd, &old_fds_set);
    int change_fds = 0;
    char buf_read[SIZE] = "";
    char buf_write[SIZE] = "";
    while (1) {
        rst_fds_set = old_fds_set;
        change_fds = select(max_fd + 1, &rst_fds_set, NULL, NULL, NULL);
        if (-1 == change_fds) {
            perror("select error");
            return -1;
        }
        printf("select\n");
        if (0 == change_fds) {
            continue;
        }
        if (FD_ISSET(lfd, &rst_fds_set)) {
            struct sockaddr_in cli_addr;
            socklen_t len = sizeof(cli_addr);
            int cfd = Accept(lfd, (struct sockaddr*)&cli_addr, &len);
            if (-1 == cfd) {
                return -1;
            }
            FD_SET(cfd, &old_fds_set);
            if (cfd > max_fd) {
                max_fd = cfd;
            }
            if (--change_fds == 0) {
                continue;
            }
        }
        for (int i = lfd + 1; i <= max_fd; i++) {
            if (FD_ISSET(i, &rst_fds_set)) {
                printf("fd:%d change.\n", i);
                memset(buf_read, 0, SIZE);
                ret = Read(i, buf_read, SIZE);
                int len = strlen(buf_read);
                if (len > 0 && buf_read[len - 1] == '\n') {
                    buf_read[len - 1] = '\0';
                }
                if (-1 == ret) {
                    close(i);
                    FD_CLR(i, &old_fds_set);
                    continue;
                } else if (0 == ret) {
                    printf("client close\n");
                    close(i);
                    FD_CLR(i, &old_fds_set);
                } else {
                    printf("reading: %s\n", buf_read);
                    memset(buf_write, 0, SIZE);
                    sprintf(buf_write, "confirm received: %s", buf_read);
                    printf("write to remote: %s\n", buf_read);
                    Write(i, buf_write, sizeof(buf_write));
                    printf("length of write:%d\n", sizeof(buf_write));
                }
            }
        }
    }

    return 0;
}