/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：wrap_err.h
*   Author：leekaihua
*   Date：20240524
*   Brife：
*



*/
#ifndef __WRAP_ERR_H
#define __WRAP_ERR_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Perror(const char* s);

#endif