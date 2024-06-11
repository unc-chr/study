/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：b.cpp
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#include "b.h"

void B::show_info() {
    arg1_->report();
}

void B::report() {
    std::cout << "B class" << std::endl;
}