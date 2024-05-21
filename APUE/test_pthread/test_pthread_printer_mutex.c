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

// global mutex
pthread_mutex_t mutex;

// printer device, a shared resource
// maybe cause resource competition trouble
// this is critical code generally.
void printer(char* str) {
    while (*str != '\0') {
        putchar(*str);
        fflush(stdout);
        str++;
        usleep(100000);
    }
    printf("\n");
}

void* printer1(void* args) {
    char* str = "hello";
    pthread_mutex_lock(&mutex);
    printer(str);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* printer2(void* args) {
    char* str = "world";
    pthread_mutex_lock(&mutex);
    printer(str);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t tid1;
    pthread_t tid2;
    int ret = -1;

    // mutex init
    ret = pthread_mutex_init(&mutex, NULL);
    if (0 != ret) {
        printf("pthread_mutex_init failed...\n");
        return 1;
    }
    printf("initializing mutex successfully...\n");

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

    // destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}