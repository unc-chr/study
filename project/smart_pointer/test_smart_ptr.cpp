/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_smart_ptr.cpp
*   Author：leekaihua
*   Date：20240602
*   Brife：
*



*/
#include <iostream>

#include "smart_ptr.h"

using namespace lee::util;

class Test {
public:
    Test() = default;
    ~Test() {
        std::cout << "Test is deleted." << std::endl;
    }
private:
};

int main() {
    SmartPtr<int> sp(new int(0));
    SmartPtr<Test> sp1(new Test);
    return 0;
}
