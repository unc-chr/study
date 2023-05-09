/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2022年01月05日
*   Brife：
*



*/
#include "cow.h"
#include <iostream>

int main() {

    char name_test[20] = "leekaihua";

    {
    Cow leekaihua;
    leekaihua.ShowCow();

    Cow A("Bob", "coding C++", 77);
    A.ShowCow();

    Cow B = A;
    B.ShowCow();

    Cow C;
    C = A;
    C.ShowCow();
    }

    return 0;
}