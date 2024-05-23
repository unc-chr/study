/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_pthread_create.c
*   Author：leekaihua
*   Date：20240521
*   Brife：
*



*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* fun(void* arg) {
    printf("new thread execute, tid: %lu\n", pthread_self());
    return NULL;
}

void* fun2(void* arg) {
    int var = (int)(long)arg;
    printf("thread2 execute, tid: %d\n", var);
    return NULL;
}

int main() {
    pthread_t tid = -1;
    pthread_t tid2 = -1;
    int ret = -1;
    // create thread
    ret = pthread_create(&tid, NULL, fun, NULL);
    if (0 != ret) {
        printf("pthread_create failed...\n");
        return 1;
    }
    ret = pthread_create(&tid2, NULL, fun2, (void*)0x3);
    if (0 != ret) {
        printf("pthread_create failed...\n");
        return 1;
    }
    printf("main thread ... tid：%lu\n", pthread_self());
    sleep(1);
    printf("press any key to continue...\n");
    getchar();

    return 0;
}