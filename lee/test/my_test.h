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
    MyTest(const MyTest& other);
    MyTest& operator=(const MyTest& other);
    MyTest(MyTest&& other);
    MyTest& operator=(MyTest&& other);
    void set_data_int(int data);
    void report();
private:
    static int count;
    int _order;
    int _data_int;
    int* _data_int_p;
};
}
}