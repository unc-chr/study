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
#include <string.h>
#include <unistd.h>

thread_pool* pool = NULL;

void test(void* args) {
    printf("-----call begin:%s-----\n", __func__);
    printf("args: %d\n", *(int*)args);
}

void* thread_run(void* args) {
    printf("-----call begin:%s-----\n", __func__);
    while (1) {
        // 抢锁，保护任务队列
        pthread_mutex_lock(&pool->mutex);
        // 如果没有任务可以执行，那么阻塞等待
        if (is_empty_queue_loop(pool->queue) == TRUE && pool->shutdown == 0) {
            pthread_cond_wait(&pool->jobs_not_empty, &pool->mutex);
        }

        // 如果还有任务未结束，先执行完任务
        if (is_empty_queue_loop(pool->queue) == FALSE) {
            // 将任务提取出来，然后尽快释放锁
            job* job = pop_from_queue_loop(pool->queue);
            job->task(job->args);
            // 释放锁
            pthread_mutex_unlock(&pool->mutex);
            // 有了空槽位，通知任务管理器添加任务
            pthread_cond_signal(&pool->jobs_not_full);
        }

        // 如果是要结束线程
        if (pool->shutdown) {
            // 释放锁
            pthread_mutex_unlock(&pool->mutex);
            // 退出死循环，线程自然结束
            // 也可以 pthread_exit，显式结束线程
            break;
        }
        pthread_mutex_unlock(&pool->mutex);
    }

    printf("-----call begin:%s-----\n", __func__);
    return NULL;
}

void thread_pool_create() {
    printf("-----call begin:%s-----\n", __func__);

    // 线程池初始化
    pool = (thread_pool*)malloc(sizeof(thread_pool));
    memset(pool, 0, sizeof(*pool));
    pool->queue = queue_loop_create(QUEUE_CAPACITY);
    pool->shutdown = 0;
    pthread_cond_init(&(pool->jobs_not_empty), NULL);
    pthread_cond_init(&(pool->jobs_not_full), NULL);
    pthread_mutex_init(&(pool->mutex), NULL);
    pool->thread_workers = (pthread_t*)malloc(sizeof(pthread_t*) * POOL_CAPACITY);
    memset(pool->thread_workers, 0, sizeof(*pool->thread_workers));

    // 为线程池生成工作线程
    for (int i = 0; i < POOL_CAPACITY; i++) {
        pthread_create(&pool->thread_workers[i], NULL, thread_run, NULL);
    }
}

void thread_pool_destroy(thread_pool* pool) {
    printf("-----call begin:%s-----\n", __func__);

    // 执行线程池的销毁操作
    // 1 让所有的线程结束
    pool->shutdown = 1;
    pthread_cond_broadcast(&pool->jobs_not_empty);
    // 2 执行线程资源回收
    for (int i = 0; i < POOL_CAPACITY; i++) {
        pthread_join(pool->thread_workers[i], NULL);
    }

    // 3 释放线程池的资源
    free(pool->thread_workers);
    pthread_mutex_destroy(&(pool->mutex));
    pthread_cond_destroy(&(pool->jobs_not_full));
    pthread_cond_destroy(&(pool->jobs_not_empty));
    free(pool->queue);
    free(pool);
    printf("-----call end:%s-----\n", __func__);
}

void* job_manager(void* args) {
    printf("-----call begin:%s-----\n", __func__);
    for (int i = 0; i < TEST_ROUND; i++) {
        // 先抢互斥锁，对任务队列进行保护
        pthread_mutex_lock(&(pool->mutex));
        // 判断是否有槽位空闲，没有空余槽位则阻塞等待
        if (is_full_queue_loop(pool->queue) == TRUE) {
            pthread_cond_wait(&(pool->jobs_not_full), &(pool->mutex));
        }
        // 任务信息
        int* count = (int*)malloc(sizeof(int));
        memset(count, 0, sizeof(*count));
        *count = i;
        job* new_job = job_create(i, test, (void*)count);
        // 提交任务
        push_to_queue_loop(pool->queue, new_job);
        // 提交任务后，释放锁
        pthread_mutex_unlock(&(pool->mutex));
        // 通知消费者线程池执行任务
        pthread_cond_signal(&pool->jobs_not_empty);
    }

    return NULL;
}

int main() {
    printf("-----call begin:%s-----\n", __func__);
    thread_pool_create();
    // 生产者，消费者模型
    // 生产者线程，进行任务提交
    pthread_t producer;
    pthread_create(&producer, NULL, job_manager, NULL);
    // 消费者就是线程池中的多个线程
    pthread_join(producer, NULL);
    printf("producer done\n");

    sleep(10);
    thread_pool_destroy(pool);

    return 0;
}
