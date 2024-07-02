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
        : _order(count++) {
    std::cout << "create MyTest instance: "
            << _order
            << std::endl;
    _data_int = 0;
    _data_int_p = new int[10];
}

MyTest::~MyTest() {
    delete[] _data_int_p;
    std::cout << "detroy MyTest instance: "
            << _order
            << std::endl;
}

MyTest::MyTest(const MyTest& other) {
    _order = count++;
    _data_int = other._data_int;
    _data_int_p = new int[10];
    for (int i = 0; i < 10; i++) {
        _data_int_p[i] = other._data_int_p[i];
    }
    std::cout << "copy and create Mytest instance "
            << _order << " from " << other._order << std::endl;
}

MyTest& MyTest::operator=(const MyTest& other) {
    if (this == &other) {
        return *this;
    }
    _data_int = other._data_int;
    for (int i = 0; i < 10; i++) {
        _data_int_p[i] = other._data_int_p[i];
    }
    std::cout << "change Mytest instance "
            << _order << " to " << other._order
            << " with copy assign." << std::endl;
    return *this;
}

MyTest::MyTest(MyTest&& other) {
    _order = count++;
    _data_int = other._data_int;
    _data_int_p = other._data_int_p;
    other._data_int_p = nullptr;
    std::cout << "move and create Mytest instance "
            << _order << " from " << other._order << std::endl;
}

MyTest& MyTest::operator=(MyTest&& other) {
    if (this == &other) {
        return *this;
    }
    _data_int = other._data_int;
    _data_int_p = other._data_int_p;
    other._data_int_p = nullptr;
    std::cout << "change Mytest instance "
            << _order << " to " << other._order
            << " with move assign." << std::endl;
    return *this;
}

void MyTest::set_data_int(int data) {
    _data_int = data;
}

void MyTest::report() {
    std::cout << ">>>>>--------report------<<<<<" << std::endl;
    std::cout << "** Class MyTest, instace: " << _order << std::endl;
    std::cout << "** data_int: " << _data_int << std::endl;
    std::cout << "** data int[10] addr: " << _data_int_p << "~" << _data_int_p + 10 << std::endl;
    std::cout << ">>>>>-----report end-----<<<<<" << std::endl;
}

}
}