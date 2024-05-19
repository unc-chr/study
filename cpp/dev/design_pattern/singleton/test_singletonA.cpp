/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_singleton.cpp
*   Author：leekaihua
*   Date：2024年03月27日
*   Brife：
*



*/
#include "SingletonA.h"

int main() {
    SingletonA::instance()->show();

    return 0;
}
