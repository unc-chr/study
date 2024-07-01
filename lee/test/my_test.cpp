/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：my_test.cpp
*   Author：leekaihua
*   Date：20240630
*   Brife：
*



*/
#include "my_test.h"

#include <iostream>

namespace lee {
namespace test {

int MyTest::count = 0;

MyTest::MyTest()
        : order_(count++) {
    std::cout << "create MyTest instance: "
            << order_
            << std::endl;
}

MyTest::~MyTest() {
    std::cout << "detroy MyTest instance: "
            << order_
            << std::endl;
}

void MyTest::report() {
    std::cout << "Class MyTest, instace: "
            << order_
            << std::endl;
}

}
}