/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：tcp_server.c
*   Author：leekaihua
*   Date：20240523
*   Brife：
*



*/

#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main() {
    // create socket
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("socket created successfully...\n");

    // bind ip and port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "192.168.58.130", &addr.sin_addr.s_addr);
    int ret = bind(lfd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret < 0) {
        perror("bind");
        return 1;
    }
    printf("bind successfully...\n");

    // listen
    listen(lfd, 128);
    printf("listen finished...\n");

    // accpet
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    int cfd = accept(lfd, (struct sockaddr*)&cliaddr, &len);
    if (cfd < 0) {
        perror("accept");
        close(cfd);
        return 1;
    }
    char ip[16] = "";
    printf("new client ip=%s port=%d\n", 
            inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16),
            ntohs(cliaddr.sin_port));

    // read and write data
    char buf[1024] = "";
    ssize_t n = 0;
    while (1) {
        memset(buf, 0, sizeof(buf));
        printf("wait for reading...\n");
        n = read(cfd, buf, sizeof(buf));
        if (n <= 0) {
            break;
        }
        printf("read from remote: %s\n", buf);

        printf("wait for input: \n");
        memset(buf, 0, sizeof(buf));
        n = read(STDIN_FILENO, buf, sizeof(buf));
        if (n <= 0) {
            break;
        }
        write(cfd, buf, n);
        printf("send out: %s\n", buf);
    }

    // close
    close(cfd);
    close(lfd);

    return 0;
}