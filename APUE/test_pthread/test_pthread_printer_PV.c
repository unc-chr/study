/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_pthread_printer.c
*   Author：leekaihua
*   Date：20240521
*   Brife：
*



*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// semanphore
sem_t sem;

// printer device, a shared resource
// maybe cause resource competition trouble
// this is critical code generally.
void printer(char* str) {
    while (*str != '\0') {
        putchar(*str);
        fflush(stdout);
        str++;
        usleep(100000);
    }
    printf("\n");
}

void* printer1(void* args) {
    char* str = "hello";
    // P operation
    sem_wait(&sem);
    printer(str);
    // V operation
    sem_post(&sem);
    return NULL;
}

void* printer2(void* args) {
    char* str = "world";
    // P operation
    sem_wait(&sem);
    printer(str);
    // V operation
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t tid1;
    pthread_t tid2;
    int ret = -1;

    // init semanphore
    ret = sem_init(&sem, 0, 1);
    if (0 != ret) {
        perror("sem_init");
        return 1;
    }

    // create pthread
    ret = pthread_create(&tid1, NULL, printer1, NULL);
    if (0 != ret) {
        printf("pthread_create failed...\n");
        return 1;
    }
    ret = pthread_create(&tid2, NULL, printer2, NULL);
    if (0 != ret) {
        printf("pthread_create failed...\n");
        return 1;
    }

    // wait thread executing...
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("\n");
    printf("main thread exit...\n");

    // destroy semanphore
    ret = sem_destroy(&sem);
    if (0 != ret) {
        perror("sem_destroy");
        return 1;
    }

    return 0;
}