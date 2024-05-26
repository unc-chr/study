/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：select.c
*   Author：leekaihua
*   Date：20240526
*   Brife：
*



*/
#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include "../../wrapped_func/wrap_sys.h"
#include "../../wrapped_func/wrap_sig.h"

#define PORT 8888
#define IP "192.168.58.130"

int main() {
    // create socket and bind
    int lfd = tcp4_bind(PORT, IP);
    // listen
    Listen(lfd, 128);
    // while
    // highest-numbered file descriptor
    int maxfd = lfd;
    fd_set oldset;
    fd_set rset;
    FD_ZERO(&oldset);
    FD_ZERO(&rset);
    // add lfd to oldset
    FD_SET(lfd, &oldset);
    while (1) {
        printf("loop\n");
        rset = oldset;
        int n = select(maxfd + 1, &rset, NULL, NULL, NULL);
        if (n < 0) {
            perror("select");
            break;
        } else if (n == 0) {
            continue;
        } else {
            // lfd watched
            if (FD_ISSET(lfd, &rset)) {
                struct  sockaddr_in cli_addr;
                socklen_t len = sizeof(cli_addr);
                char ip[16] = "";
                int cfd = Accept(lfd, (struct sockaddr*)&cli_addr, &len);
                printf("new client ip=%s port=%d\n", inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip, 16), ntohs(cli_addr.sin_port));
                // add cfd to oldset for next monitor
                FD_SET(cfd, &oldset);
                if (cfd > maxfd) {
                    maxfd = cfd;
                }
                // 如果只有 lfd 变化，continue
                if (--n == 0) {
                    continue;
                }
            }
            // cfd 遍历 lfd 之后的文件描述符是否在 reset 集合中，如果在则 cfd 变化
            printf("cfd change\n");
            for (int i = lfd + 1; i <= maxfd; i++) {
                // 如果文件描述符 i 在 rset 集合中
                printf("loop\n");
                if (FD_ISSET(i, &rset)) {
                    printf("cfd do work\n");
                    char buf[1500] = "";
                    int ret = Read(i, buf, sizeof(buf));
                    // 出错，将 cfd 关闭，从 oldset 中删除 cfd
                    printf("fd: %d\n", i);
                    if (ret < 0) {
                        perror("read");
                        close(i);
                        FD_CLR(i, &oldset);
                        continue;
                    } else if (ret == 0) {
                        printf("client close\n");
                        close(i);
                        FD_CLR(i, &oldset);
                    } else {
                        printf("read: %s\n", buf);
                        Write(i, buf, ret);
                    }
                }
            }
        }
    }
    // select listen
    return 0;
}