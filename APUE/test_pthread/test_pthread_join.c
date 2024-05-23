/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_pthread_join.c
*   Author：leekaihua
*   Date：20240521
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* fun(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("fun thread do work: %d\n", i);
        sleep(1);
    }
    return (void*)0x3;
}

int main() {
    pthread_t tid = -1;
    void* retp = NULL;
    int ret = -1;
    ret = pthread_create(&tid, NULL, fun, NULL);
    if (0 != ret) {
        printf("pthread_create failed...\n");
        return 1;
    }

    // wait thread finish
    // pthread_join will block
    ret = pthread_join(tid, &retp);
    if (0 != ret) {
        printf("pthread_join failed!...\n");
        return 1;
    }
    printf("retp = %p\n", retp);
    printf("main thread finish...\n");
    return 0;
}