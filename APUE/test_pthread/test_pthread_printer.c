/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_pthread_printer.c
*   Author：leekaihua
*   Date：20240521
*   Brife：
*



*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* printer1(void* args) {
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        putchar(ch);
        fflush(stdout);
        usleep(100000);
    }
    return NULL;
}

void* printer2(void* args) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
        putchar(ch);
        fflush(stdout);
        usleep(100000);
    }
    return NULL;
}

int main() {
    pthread_t tid1;
    pthread_t tid2;
    int ret = -1;

    // create pthread
    ret = pthread_create(&tid1, NULL, printer1, NULL);
    if (0 != ret) {
        printf("pthread_create failed...\n");
        return 1;
    }
    ret = pthread_create(&tid2, NULL, printer2, NULL);
    if (0 != ret) {
        printf("pthread_create failed...\n");
        return 1;
    }

    // wait thread executing...
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("\n");
    printf("main thread exit...\n");

    return 0;
}