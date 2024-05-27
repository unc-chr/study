/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：epoll.c
*   Author：leekaihua
*   Date：20240527
*   Brife：
*



*/
#include "../../wrapped_func/wrap_sys.h"
#include "../../wrapped_func/wrap_sig.h"

#include <stdio.h>
#include <sys/epoll.h>

#define IP "192.168.58.130"
#define PORT 8888
#define BACKLOG 128
#define EPOLL_MAX_EVENT 1024

int main() {
    // create socket and bind
    int lfd = tcp4_bind(PORT, IP);
    if (-1 == lfd) {
        return -1;
    }
    // listen
    Listen(lfd, BACKLOG);
    // create a tb tree
    int efd = epoll_create(1);
    if (-1 == efd) {
        perror("epoll_create");
        return 1;
    }
    // add lfd to rb tree
    struct epoll_event event_lfd;
    event_lfd.events = EPOLLIN;
    event_lfd.data.fd = lfd;
    epoll_ctl(efd, EPOLL_CTL_ADD, lfd, &event_lfd);
    // epoll event array
    struct epoll_event epoll_events[EPOLL_MAX_EVENT];
    // loop listening and do work
    while (1) {
        // listening client connection with epoll_wait 
        int num_ready = epoll_wait(efd, epoll_events, EPOLL_MAX_EVENT, -1);
        if (num_ready < 0) {
            perror("epoll_wait error");
            break;
        }
        if (num_ready == 0) {
            continue;
        }
        // look into events and check event
        for (int i = 0; i < num_ready; i++) {
            // The changed event is lfd
            if (epoll_events[i].data.fd == lfd && epoll_events[i].events & EPOLLIN) {
                // accept and new cfd create
                struct sockaddr_in cli_addr;
                socklen_t len = sizeof(cli_addr);
                int cfd = Accept(lfd, (struct sockaddr*)&cli_addr, &len, 1);
                if (-1 == cfd) {
                    return 1;
                }
                // add new cfd to rb tree
                struct epoll_event event_cfd;
                event_cfd.data.fd = cfd;
                event_cfd.events = EPOLLIN;
                epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &event_cfd);
            } else if (epoll_events[i].events & EPOLLIN) {
                char buf[1024] = "";
                memset(buf, 0, sizeof(buf));
                int ret = Read(epoll_events[i].data.fd, buf, sizeof(buf));
                if (-1 == ret) {
                    epoll_ctl(efd, EPOLL_CTL_DEL, epoll_events[i].data.fd, &epoll_events[i]);
                    continue;
                } else if (0 == ret) {
                    printf("close client.\n");
                    epoll_ctl(efd, EPOLL_CTL_DEL, epoll_events[i].data.fd, &epoll_events[i]);
                    continue;
                } else {
                    printf("%s\n", buf);
                    Write(epoll_events[i].data.fd, buf, sizeof(buf));
                }
            }
        }
    }
    return 0;
}