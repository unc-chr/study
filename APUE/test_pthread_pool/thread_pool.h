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

#define POOL_CAPACITY 20

// job
typedef struct {
    // 任务编号
    int job_id;
    // 任务执行函数的句柄
    void (*task)(void* args);
    // 任务执行的参数
    void* args;
} job;

// thread pool
typedef struct {
    // 任务队列，循环数组实现
    job* jobs[POOL_CAPACITY];
    // 当前处理的任务索引
    int job_curr;
    // 最新提交的任务索引
    int job_new;
    // 条件变量，同步任务队列和执行器
    pthread_cond_t jobs_ready;
    // 条件变量，同步任务队列和任务提交
    pthread_cond_t jobs_empty;
    // 互斥锁，保护任务队列
    pthread_cond_t mutex;
} thread_pool;

// 创建线程池
thread_pool* thread_pool_create();
// 销毁线程池
void thread_pool_destroy(thread_pool* pool);
// 任务管理器，提交任务
void job_manager();
// 任务执行器，执行任务
void job_execute();

#endif