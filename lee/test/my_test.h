/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：my_test.h
*   Author：leekaihua
*   Date：20240630
*   Brife：
*



*/
#pragma once

namespace lee {
namespace test {
class MyTest {
public:
    MyTest();
    ~MyTest();
    void report();
private:
    static int count;
    int order_;
};
}
}