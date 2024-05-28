/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：loop_array.c
*   Author：leekaihua
*   Date：20240528
*   Brife：
*



*/
#include "loop_array.h"
#include <stdlib.h>

queue_loop* queue_loop_create(int capacity) {
    queue_loop* queue = (queue_loop*)malloc(sizeof(queue_loop));
    queue->pos_pop = 0;
    queue->pos_push = 0;
    queue->size = 0;
    queue->capacity = capacity;
    queue->queue_array = (job**)malloc(sizeof(job*) * capacity);
    return queue;
}

int queue_loop_destroy(queue_loop* queue) {
    printf("call begin: %s-----\n", __func__);
    free(queue->queue_array);
    free(queue);
    printf("call end: %s-----\n", __func__);
    return 0;
}

int is_empty_queue_loop(queue_loop* queue) {
    if (queue->pos_pop == queue->pos_push) {
        return TRUE;
    }
    return FALSE;
}

int is_full_queue_loop(queue_loop* queue) {
    if (queue->pos_pop + queue->capacity == queue->pos_push) {
        return TRUE;
    }
    return FALSE;
}

int push_to_queue_loop(queue_loop* queue, job* ele) {
    if (is_full_queue_loop(queue) == TRUE) {
        return -1;
    }
    int real_pos_push = queue->pos_push % queue->capacity;
    queue->queue_array[real_pos_push] = ele;
    queue->pos_push++;
    queue->size++;
    return 0;
}

job* pop_from_queue_loop(queue_loop* queue) {
    if (is_empty_queue_loop(queue) == TRUE) {
        return NULL;
    }
    int real_pos_pop = queue->pos_pop % queue->capacity;
    job* temp = queue->queue_array[real_pos_pop];
    queue->pos_pop++;
    queue->size--;
    return temp;
}

int queue_size(queue_loop* queue) {
    return queue->size;
}