/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：wrap_err.c
*   Author：leekaihua
*   Date：20240524
*   Brife：
*



*/
#include "wrap_err.h"

void Perror(const char* s) {
    perror(s);
    exit(-1);
}
