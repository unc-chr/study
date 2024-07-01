/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_my_test.cpp
*   Author：leekaihua
*   Date：20240630
*   Brife：
*



*/
#include "lee/test/my_test.h"
// #include "my_test.h"

using lee::test::MyTest;

int main() {
    MyTest t1;
    MyTest t2;
    MyTest* pt1 = new MyTest();
    delete pt1;
    return 0;
}