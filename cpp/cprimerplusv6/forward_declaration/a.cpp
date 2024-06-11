/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：a.cpp
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#include "a.h"

void A::show_info() {
    arg1_->report();
}

void A::report() {
    std::cout << "A class." << std::endl;
}