/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：thread_pool.c
*   Author：leekaihua
*   Date：20240527
*   Brife：
*



*/
#include "thread_pool.h"
#include <stdio.h>
#include <stdlib.h>

void test(void* args) {
    printf("test...\n");
}

thread_pool* thread_pool_create() {
    thread_pool* pool = (struct thread_pool*)malloc(sizeof(thread_pool));
    pool->job_curr = 0;
    pool->job_new = 0;
    pthread_cond_init(&(pool->jobs_ready), NULL);
    pthread_cond_init(&(pool->jobs_empty), NULL);
    pthread_mutex_init(&(pool->mutex), NULL);
    memset(pool->jobs, 0, sizeof(pool->jobs));
}

void thread_pool_destroy(thread_pool* pool) {
    memset(pool->jobs, 0, sizeof(pool->jobs));
    pthread_mutex_destroy(&(pool->mutex));
    pthread_cond_destroy(&(pool->jobs_empty));
    pthread_cond_destroy(&(pool->jobs_ready));
    free(pool);
}

void job_manager() {
    for (int i = 0; i < POOL_CAPACITY; i++) {

    }
}

void job_execute() {

}

int main() {
    thread_pool* pool = thread_pool_create();
    return 0;
}
