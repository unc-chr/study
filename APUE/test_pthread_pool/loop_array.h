/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：loop_array.h
*   Author：leekaihua
*   Date：20240528
*   Brife：
*



*/
#ifndef __LOOP_ARRAY_H
#define __LOOP_ARRAY_H

#include "job.h"

#include <stdio.h>

#define TRUE 1
#define FALSE 0

// 循环队列
typedef struct {
    int pos_pop;            // 队首位置，即待出队元素的位置
    int pos_push;            // 队尾位置，即下一个入队的位置
    int capacity;        // 队列容量
    int size;            // 队列当前元素数量
    job** queue_array;    // 数组位置
} queue_loop;

queue_loop* queue_loop_create(int capacity);
int queue_loop_destroy(queue_loop* queue);
int is_empty_queue_loop(queue_loop* queue);
int is_full_queue_loop(queue_loop* queue);
int push_to_queue_loop(queue_loop* queue, job* ele);
job* pop_from_queue_loop(queue_loop* queue);
int queue_size(queue_loop* queue);

#endif