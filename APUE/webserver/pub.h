/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：pub.h
*   Author：leekaihua
*   Date：20240531
*   Brife：
*



*/
#pragma once

#include <ctype.h>
#include <string.h>

char* get_mime_type(char* name);
void strdecode(char *to, char *from);
int hexit(char c);