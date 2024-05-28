/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：job.h
*   Author：leekaihua
*   Date：20240528
*   Brife：
*



*/
#pragma once

#include <stdio.h>
#include <stdlib.h>

// job
typedef struct {
    // 任务编号
    int job_id;
    // 任务执行函数的句柄
    void (*task)(void* args);
    // 任务执行的参数
    void* args;
} job;

job* job_create(int v_job_id, void (*task_fun)(void*), void* v_args);
void job_destroy(job* ins);
