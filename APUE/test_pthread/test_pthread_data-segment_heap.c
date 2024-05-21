/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_pthread_data-segment_heap.c
*   Author：leekaihua
*   Date：20240521
*   Brife：
*



*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// a global variable
int num = 100;

void* fun(void* arg) {
    printf("before fun num = %d\n", num);
    num++;
    printf("after fun num = %d\n", num);
    return NULL;
}

void* fun2(void* arg) {
    int* pn = (int*)arg;
    printf("before fun2 pn = %d\n", *pn);
    (*pn)++;
    printf("after fun pn = %d\n", *pn);
    return NULL;
}
// test data segment and heap
int main() {
    int ret = -1;

    pthread_t tid;
    memset(&tid, 0, sizeof(tid));

    int* p = NULL;
    p = malloc(sizeof(int));
    if (p == NULL) {
        printf("malloc failed...\n");
        return 1;
    }
    memset(p, 0, sizeof(int));
    *p = 88;

    // create thread
    ret = pthread_create(&tid, NULL, fun, NULL);
    if (0 != ret) {
        printf("pthread_create failed\n");
        return 0;
    }
    ret = pthread_create(&tid, NULL, fun2, (void*)p);
    if (0 != ret) {
        printf("pthread_create failed\n");
        return 0;
    }

    printf("press any key to continue...\n");
    getchar();
    printf("main thread global var num = %d\n", num);
    printf("main thread heap var p = %d\n", *p);

    // release memory in heap just once
    free(p);
    return 0;
}