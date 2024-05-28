/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_queue_loop.c
*   Author：leekaihua
*   Date：20240528
*   Brife：
*



*/
#include "loop_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int assert(int a, int b) {
    if (a == b) {
        return 1;
    }
    exit(1);
}

void run(void* args) {
    printf("args: %d\n", *(int*)args);
}

int main() {
    int capacity = 10;
    queue_loop* queue = queue_loop_create(capacity);

    int ret = is_empty_queue_loop(queue);
    assert(ret, TRUE);

    job* ins;
    for (int i = 0; i < capacity; i++) {
        ins = job_create(i, run, NULL);
        ret = push_to_queue_loop(queue, ins);
        printf("pos_pop is %d, pos_push is %d\n", queue->pos_pop, queue->pos_push);
        assert(ret, 0);
    }

    ret = is_full_queue_loop(queue);
    assert(ret, TRUE);

    for (int i = 0; i < 3; i++) {
        ins = job_create(i, run, NULL);
        ret = push_to_queue_loop(queue, ins);
        assert(ret, -1);
    }

    job* pop_out = NULL;
    for (int i = 0; i < 5; i++) {
        pop_out = pop_from_queue_loop(queue);
        job_destroy(pop_out);
    }

    srand(time(NULL));
    for (int i = 0; i < 500; i++) {
        printf("pos_pop is %d, pos_push is %d\n", queue->pos_pop, queue->pos_push);
        int choice = rand() % 2;
        if (choice == 0) {
            ins = job_create(i, run, NULL);
            ret = push_to_queue_loop(queue, ins);
            if (ret == 0) {
                printf("push success.\n");
            } else {
                printf("push fail\n");
            }
        } else {
            pop_out = pop_from_queue_loop(queue);
            if (pop_out != NULL) {
                printf("pop success.\n");
                job_destroy(pop_out);
            } else {
                printf("pop fail\n");
            }
        }
    }

    return 0;
}
