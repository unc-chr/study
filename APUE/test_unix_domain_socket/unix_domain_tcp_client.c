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
    unlink("sock.client");
    // create AF_UNIX socket
    int cfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (cfd < 0) {
        perror("socket error");
        return 1;
    }
    printf("socket crated.\n");

    // 如果不绑定，就是隐式绑定
    struct sockaddr_un my_addr;
    my_addr.sun_family = AF_UNIX;
    socklen_t len = sizeof(my_addr);
    strcpy(my_addr.sun_path, "sock.client");
    if (bind(cfd, (struct sockaddr*)&my_addr, len) < 0) {
        perror("bind error");
        return 1;
    }
    printf("bind done.\n");

    // connect
    struct sockaddr_un ser_addr;
    ser_addr.sun_family = AF_UNIX;
    strcpy(ser_addr.sun_path, "sock.server");
    int ret = connect(cfd, (struct sockaddr*)&ser_addr, sizeof(ser_addr));
    if (ret < 0) {
        perror("connect error");
        return 1;
    }
    printf("connect done");
    printf("new client file = %s\n", ser_addr.sun_path);

    // read/write
    char buf[1000] = "";
    while (1) {
        printf("Enter something:\n");
        memset(buf, 0, sizeof(buf));
        int n = read(STDIN_FILENO, buf, sizeof(buf));
        n = send(cfd, buf, n, 0);
        memset(buf, 0, sizeof(buf));
        n = recv(cfd, buf, sizeof(buf), 0);
        if (n <= 0) {
            printf("err or server close\n");
            break;
        } else {
            printf("%s\n", buf);
        }
    }
    close(cfd);

    return 0;
}