/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：golf.h
*   Author：leekaihua
*   Date：2021年12月31日
*   Brife：
*



*/
#pragma once
const int Len = 40;
struct golf {
    char fullname[Len];
    int handicap;
};

void setgolf(golf& g, const char* name, int hc);
int setgolf(golf& g);
void handicap(golf&g, int hc);
void showgolf(const golf& g);