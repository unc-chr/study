/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_time.c
*   Author：leekaihua
*   Date：20240521
*   Brife：
*



*/
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 32

int main() {
    time_t t = -1;
    struct tm* pt = NULL;
    char file_name[SIZE];

    // get time
    t = time(NULL);
    if (-1 == t) {
        perror("time");
        return 1;
    }
    printf("time: %ld\n", t);
    printf("ctime: %s\n", ctime(&t));
    // convert to time
    pt = localtime(&t);
    if (NULL == pt) {
        printf("localtime failed!");
        return 1;
    }
    printf("year: %d\n", pt->tm_year + 1900);
    printf("month: %d\n", pt->tm_mon + 1);
    printf("day: %d\n", pt->tm_mday);
    printf("hour: %d\n", pt->tm_hour);
    printf("min: %d\n", pt->tm_min);
    printf("second: %d\n", pt->tm_sec);
    // convert time to file name
    memset(file_name, 0, SIZE);
    sprintf(file_name, "touch %d%02d%02d%02d%02d%02d.log", pt->tm_year + 1900, 
                                pt->tm_mon + 1,
                                pt->tm_mday,
                                pt->tm_hour,
                                pt->tm_min,
                                pt->tm_sec);
    printf("file_name: %s\n", file_name);

    // create a file with specific file name
    system(file_name);
    
    return 0;
}