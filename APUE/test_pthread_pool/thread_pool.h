/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：thread_pool.h
*   Author：leekaihua
*   Date：20240527
*   Brife：
*



*/
#ifndef __THREAD_POOL_H
#define __THREAD_POOL_H

#include <pthread.h>
#include "job.h"
#include "loop_array.h"

#define POOL_CAPACITY 5
#define QUEUE_CAPACITY 10
#define TEST_ROUND 30

// thread pool
typedef struct {
    // 任务队列
    queue_loop* queue;

    // 条件变量，同步任务队列和执行器
    pthread_cond_t jobs_not_empty;
    // 条件变量，同步任务队列和任务提交
    pthread_cond_t jobs_not_full;
    // 互斥锁，保护任务队列
    pthread_mutex_t mutex;
    // 线程池销毁标记
    int shutdown;

    // 线程池
    pthread_t* thread_workers;
} thread_pool;

// 创建线程池
void thread_pool_create();
// 销毁线程池
void thread_pool_destroy(thread_pool* pool);
// 任务管理器，提交任务
void* job_manager(void* args);
// 任务执行器，执行任务
void* job_execute(void* args);

#endif