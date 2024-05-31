/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：udp_server.c
*   Author：leekaihua
*   Date：20240529
*   Brife：
*



*/

#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
    // create socket
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1) {
        perror("socket error");
        return 1;
    }

    // bind
    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(8888);
    my_addr.sin_addr.s_addr = inet_addr("192.168.58.130");
    int ret = bind(fd, (struct sockaddr*)&my_addr, sizeof(my_addr));
    if (ret < 0) {
        perror("bind error");
        return 1;
    }

    // read/write
    char buf[1500] = "";
    struct sockaddr_in cli_addr;
    socklen_t len = sizeof(cli_addr);
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(8888);
    dest_addr.sin_addr.s_addr = inet_addr("192.168.58.130");
    int n = -1;
    while (1) {
        n = read(STDIN_FILENO, buf, sizeof(buf));
        sendto(fd, buf, n, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
        memset(buf, 0, sizeof(buf));
        recvfrom(fd, buf, sizeof(buf), 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            break;
        } else {
            printf("%s\n", buf);
        }
    }

    // close
    close(fd);
    return 0;
}