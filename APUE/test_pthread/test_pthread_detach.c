/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_pthread_detach.c
*   Author：leekaihua
*   Date：20240521
*   Brife：
*



*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* fun(void* args) {
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        putchar(ch);
        fflush(stdout);
        usleep(100000);
    }
    return NULL;
}

int main() {
    pthread_t tid1;
    int ret = -1;

    // create pthread
    ret = pthread_create(&tid1, NULL, fun, NULL);
    if (0 != ret) {
        printf("pthread_create failed...\n");
        return 1;
    }

    // pthread_detach
    pthread_detach(tid1);
    if (0 != ret) {
        perror("pthread_detach");
        return 1;
    }
    printf("\n");
    printf("press any key to continue ...\n");
    getchar();

    return 0;
}