/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：b.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#pragma once

#include <iostream>

#include "a.h"

class A;
class B {
public:
    void show_info();
    void report();
private:
    A* arg1_;
};