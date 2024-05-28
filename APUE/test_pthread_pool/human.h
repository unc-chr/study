/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：human.h
*   Author：leekaihua
*   Date：20240528
*   Brife：
*



*/
#pragma once

typedef struct {
    char* name;
    int age;
    char student_id[10];
} student;

typedef struct {
    char* name;
    int age;
    char teacher_id[10];
    int level;
} teacher;

typedef struct {
    char* name;
    int age;
    char worker_id[10];
    int salary;
} school_worker;