/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：job.c
*   Author：leekaihua
*   Date：20240528
*   Brife：
*



*/
#include "job.h"

job* job_create(int v_job_id, void (*task_fun)(void*), void* v_args) {
    job* ins = (job*)malloc(sizeof(job));
    ins->job_id = v_job_id;
    ins->task = task_fun;
    ins->args = v_args;
    return ins;
}

void job_destroy(job* ins) {
    printf("call begin: %s-----\n", __func__);
    free(ins->args);
    ins->args = NULL;
    free(ins);
    printf("call end: %s-----\n", __func__);
}
