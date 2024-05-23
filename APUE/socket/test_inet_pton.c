/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_inet_pton.c
*   Author：leekaihua
*   Date：20240523
*   Brife：
*



*/

#include <stdio.h>
#include <arpa/inet.h>

int main() {
    // define a IPv4 address in text format
    char ip[] = "192.168.1.32";
    unsigned int net_ip;

    // convert from text format to binary form
    int ret = inet_pton(AF_INET, ip, &net_ip);
    if (1 != ret) {
        if (0 == ret) {
            printf("illegal ip address.\n");
            return 1;
        }
        if (-1 == ret) {
            perror("inet_pton");
            return 1;
        }
    }

    // printf binary form
    unsigned char* p = &net_ip;
    printf("net_ip %u.%u.%u.%u\n", *p, *(p + 1), *(p + 2), *(p + 3));

    // convert binary format back to text format
    char local_ip[16] = "";
    const char* ret_p = inet_ntop(AF_INET, &net_ip, local_ip, 16);
    if (NULL == ret_p) {
        perror("inet_ntop");
        return 1;
    }

    // printf text format
    printf("local_ip: %s\n", local_ip);

    return 0;
}