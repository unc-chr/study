/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：unix_domain_tcp_server.c
*   Author：leekaihua
*   Date：20240529
*   Brife：
*



*/

#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
    unlink("sock.server");
    // create AF_UNIX socket
    int lfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (lfd < 0) {
        perror("socket error");
        return 1;
    }
    printf("socket created.\n");

    // bind
    struct sockaddr_un my_addr;
    my_addr.sun_family = AF_UNIX;
    strcpy(my_addr.sun_path, "sock.server");
    // int len = offsetof(struct sockaddr_un, sun_path) + strlen(my_addr.sun_path);
    socklen_t len = sizeof(my_addr);
    int ret = bind(lfd, (struct sockaddr*)&my_addr, len);
    if (ret < 0) {
        perror("bind error");
        return 1;
    }
    printf("bind done.\n");

    // listen
    listen(lfd, 128);
    printf("listen done.\n");

    // accept
    struct sockaddr_un cli_addr;
    len = sizeof(cli_addr);
    int cfd = accept(lfd, (struct sockaddr*)&cli_addr, &len);
    printf("new client file = %s\n", cli_addr.sun_path);

    // read/write
    char buf[1000] = "";
    while (1) {
        int n = recv(cfd, buf, sizeof(buf), 0);
        if (n <= 0) {
            printf("err or client close\n");
            break;
        } else {
            printf("%s\n", buf);
            send(cfd, buf, n, 0);
        }
    }
    close(cfd);
    close(lfd);

    return 0;
}