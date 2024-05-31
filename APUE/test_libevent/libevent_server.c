/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：libevent_server.c
*   Author：leekaihua
*   Date：20240529
*   Brife：
*



*/

#include <stdio.h>

#include <event.h>

#include "../wrapped_func/wrap_sys.h"

#define IP "192.168.58.130"
#define PORT 8888

void cfdcb(int cfd, short event, void* arg) {
    char buf[1500] = "";
    int n = Read(cfd, buf, sizeof(buf));
    if (n <= 0) {
        // 下树
        event_del();
    } else {
        printf("%s\n", buf);
        Write(cfd, buf, n);
    }
}

void lfdcb(int lfd, short event, void* arg) {
    struct event_base* base = (struct event_base*)arg;
    // 提取新的 cfd
    int cfd = Accept(lfd, NULL, NULL);
    // 将 cfd 上树
    struct event* ev = event_new(base, cfd, EV_READ |  EV_PERSIST, cfdcb, NULL);
    event_add(ev, NULL);
}

int main() {
    // 创建套接字，绑定
    int lfd = tcp4_bind(PORT, IP);
    if (lfd < 0) {
        return 1;
    } 

    // 监听
    Listen(lfd, 128);

    // 创建 event_base 根节点
    struct event_base* base = event_base_new();

    // 初始化 lfd 上树节点
    struct event* ev = event_new(base, lfd, EV_READ |  EV_PERSIST, lfdcb, base);

    // 上树
    event_add(ev, NULL);

    // 循环监听
    event_base_dispatch(base);  // 阻塞

    // 收尾
    close(lfd);
    event_base_free(base);

    return 0;
}