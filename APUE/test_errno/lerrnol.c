/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：lerrnol.c
*   Author：leekaihua
*   Date：2024年05月17日
*   Brife：
*



*/
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE* fp = fopen("txt", "r");
    if (NULL == fp) {
        printf("fopen failed!\n");
        printf("errno: %d\n", errno);
        printf("fopen: %s\n", strerror(errno));
        perror("fopen:");

        return 1;
    }
    
    return 0;
}
