/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_read_write_lock.c
*   Author：leekaihua
*   Date：20240522
*   Brife：
*



*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// global variable
int num = 0;
pthread_rwlock_t rwlock;

void* fun_read(void* args) {
    // get thread number
    int index = (int)(long)args;
    while (1) {
        // read lock
        pthread_rwlock_rdlock(&rwlock);
        printf("thread:%d read num %d\n", index, num);
        // read unlock
        pthread_rwlock_unlock(&rwlock);
        sleep(random() % 3 + 1);
    }
    return NULL;
}

void* fun_write(void* args) {
    // get thread number
    int index = (int)(long)args;
    while (1) {
        // write lock
        pthread_rwlock_wrlock(&rwlock);
        printf("thread:%d write %d -> %d\n", index, num, num + 1);
        num++;
        // unlock write lock
        pthread_rwlock_unlock(&rwlock);
        sleep(random() % 3 + 1);
    }
    return NULL;
}

int main() {
    pthread_t tid[8];
    int ret = -1;

    // set seed of random()
    srandom(getpid());

    // init read write lock
    ret = pthread_rwlock_init(&rwlock, NULL);
    if (0 != ret) {
        printf("pthread_rwlock_init failed...\n");
        return 1;
    }

    // create 8 threads
    for (int i = 0; i < 8; i++) {
        // read thread
        if (i < 5) {
            pthread_create(&tid[i], NULL, fun_read, (void*)(long)i);
        } else {
        // write pthread
            pthread_create(&tid[i], NULL, fun_write, (void*)(long)i);
        }
    }

    // recycle 8 threads resource
    for (int i = 0; i < 8; i++) {
        pthread_join(tid[i], NULL);
    }

    // destroy read write lock
    pthread_rwlock_destroy(&rwlock);

    return 0;
}