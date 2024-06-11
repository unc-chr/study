/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：a.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#pragma once

#include <iostream>

#include "b.h"

class B;
class A {
public:
    void show_info();
    void report();
private:
    B* arg1_;
};