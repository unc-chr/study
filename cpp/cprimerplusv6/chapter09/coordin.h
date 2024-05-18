/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：coordin.h
*   Author：leekaihua
*   Date：2021年12月29日
*   Brife：
*



*/
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar {
    double distance;
    double angle;
};

struct rect {
    double x;
    double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif