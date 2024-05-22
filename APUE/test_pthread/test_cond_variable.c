/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_cond_variable.c
*   Author：leekaihua
*   Date：20240522
*   Brife：
*



*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// cv means conditional variable
pthread_cond_t cv;
// mutex
pthread_mutex_t mutex;

// global var
int flag = 0;

// thread recall function
// set flag as 1
void* func1(void* args) {
    while (1) {
        pthread_mutex_lock(&mutex);
        flag = 1;
        printf("flag 0 -> 1\n");
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cv);
        printf("func1 sleep 1s...\n");
        sleep(1);
        printf("func1 sleep another 1s...\n");
        sleep(1);
    }
    return NULL;
}

// thread recall function
// set flag as 0
void* func2(void* args) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (0 == flag) {
            pthread_cond_wait(&cv, &mutex);
        }
        printf("func2 notified, execute now...\n");
        pthread_mutex_unlock(&mutex);
        flag = 0;
        printf("flag 1 -> 0\n");
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    int ret = -1;
    pthread_t tid1;
    pthread_t tid2;

    // conditional variable init
    ret = pthread_cond_init(&cv, NULL);
    if (0 != ret) {
        perror("pthread_cond_init");
        return 1;
    }

    // mutex init
    ret = pthread_mutex_init(&mutex, NULL);
    if (0 != ret) {
        perror("pthread_mutex_init");
        return 1;
    }

    // create 2 threads
    ret = pthread_create(&tid1, NULL, func1, NULL);
    if (0 != ret) {
        perror("pthread_create");
        return 1;
    }
    ret = pthread_create(&tid2, NULL, func2, NULL);
    if (0 != ret) {
        perror("pthread_create");
        return 1;
    }

    // recycle resources of 2 threads
    ret = pthread_join(tid1, NULL);
    if (0 != ret) {
        perror("pthread_join");
        return 1;
    }
    pthread_join(tid2, NULL);
    if (0 != ret) {
        perror("pthread_join");
        return 1;
    }

    // destroy conditional variable 
    pthread_cond_destroy(&cv);

    // destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}