/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：tcp_client.c
*   Author：leekaihua
*   Date：20240523
*   Brife：
*



*/

#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define SIZE 1024
#define EXIT_COMMAND "exit\n"

int main() {
    // create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == socket_fd) {
        perror("socket");
        return -1;
    }
    printf("socket created successfully...\n");

    // init connect
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    inet_pton(AF_INET, "192.168.58.130", &addr.sin_addr.s_addr);
    int ret = connect(socket_fd, (struct sockaddr*)&addr, sizeof(addr));
    if (0 != ret) {
        perror("connect");
        return 1;
    }
    printf("connection established successfully...\n");

    // read or write data
    char buf[SIZE] = "";
    ssize_t n = 0;
    while (1) {
        printf("waitting for input:\n");
        memset(buf, 0, SIZE);
        n = read(STDIN_FILENO, buf, SIZE);
        if (n > 0 && memcmp(buf, EXIT_COMMAND, strlen(EXIT_COMMAND)) == 0) {
            break;
        } else if (n > 0) {
            printf("send out: %s\n", buf);
            write(socket_fd, buf, n);
        }

        memset(buf, 0, sizeof(buf));
        n = read(socket_fd, buf, SIZE);
        if (n > 0) {
            printf("read from remote: %s\n", buf);
        } else if (n == 0) {
            break;
        } else {
            perror("read from socket");
            break;
        }
    }
    // close socket
    close(socket_fd);
    return 0;
}