/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_pthread.c
*   Author：leekaihua
*   Date：20240521
*   Brife：
*

*/

// compile and link with -pthread
#include <stdio.h>
#include <pthread.h>

int main() {
    pthread_t tid = -1;
    // get current thread id
    tid = pthread_self();

    printf("tid: %lu\n", tid);

    if (pthread_equal(tid, pthread_self())) {
        printf("two thread id equal!\n");
    } else {
        printf("two thread id not equal!\n");
    }
    return 0;
}