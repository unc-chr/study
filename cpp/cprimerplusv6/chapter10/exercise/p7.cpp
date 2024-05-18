/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p7.cpp
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/
#include "plorg.h"
#include <iostream>

int main() {
    using namespace std;
    Plorg plorg1;
    plorg1.report();

    Plorg plorg2 = Plorg("you");
    plorg2.report();

    plorg2.reset(25);
    plorg2.report();

    return 0;
}