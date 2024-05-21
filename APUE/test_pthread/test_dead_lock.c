/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_dead_lock.c
*   Author：leekaihua
*   Date：20240521
*   Brife：
*



*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

// thread1 function
void* fun1(void* args) {
    // thread1 apply for resource1, then resource2
    pthread_mutex_lock(&mutex1);
    printf("thread1 lock resource1...\n");
    pthread_mutex_lock(&mutex2);
    printf("thread2 lock resource2...\n");
    // do sth
    printf("thread1 execute critical code....\n");

    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return NULL;
}

// thread2 function
void* fun2(void* args) {
    // thread1 apply for resource2, then resource1
    pthread_mutex_lock(&mutex2);
    printf("thread2 lock resource2...\n");
    pthread_mutex_lock(&mutex1);
    printf("thread1 lock resource1...\n");
    // do sth
    printf("thread2 execute critical code....\n");

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main() {
    pthread_t tid1;
    pthread_t tid2;
    int ret = -1;

    // init mutex
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    // create 2 threads
    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);

    // recycle thread resource
    ret = pthread_join(tid1, NULL);
    if (0 != ret) {
        printf("pthread_join failed...\n");
        return 1;
    }
    ret = pthread_join(tid2, NULL);
    if (0 != ret) {
        printf("pthread_join failed...\n");
        return 1;
    }

    // destroy mutex
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}