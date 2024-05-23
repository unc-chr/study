/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_htotl.c
*   Author：leekaihua
*   Date：20240523
*   Brife：
*



*/
#include <arpa/inet.h>
#include <stdio.h>

int main() {
    // define a ip address
    char buf[4] = {192, 168, 1, 32};
    // convert to big endian
    uint32_t local_ip = *(int*)buf;
    uint32_t net_ip = htonl(local_ip);
    // printf big endian
    unsigned char* p = &net_ip;
    printf("net ip: %u.%u.%u.%u\n", *p, *(p + 1), *(p + 2), *(p + 3));
    return 0;
}