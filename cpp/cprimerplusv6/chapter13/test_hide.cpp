/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_override.cpp
*   Author：leekaihua
*   Date：20240629
*   Brife：
*       test function hide

*/

#include <iostream>
#include <typeinfo>

class Base {
public:
    Base(int data = 10) : a_(data) {}
    virtual ~Base() = default;
    void show() {
        std::cout << "Base::show()" << std::endl;
    }
    void show(int) {
        std::cout << "Base::show(int)" << std::endl;
    }
    void report() {
        std::cout << "Base::report()" << std::endl;
    }
private:
    int a_;
};

class Derive : public Base {
public:
    Derive(int data = 10) : Base(data), b_(data) {}
    ~Derive() = default;
    bool show(double) {
        std::cout << "Derive::show(double)" << std::endl;
        return true;
    }
private:
    int b_;
};

int main() {
    Derive d;
    // d.show();
    d.show(1);
    d.show(1.1);
    d.report();

    return 0;
}