/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_override.cpp
*   Author：leekaihua
*   Date：20240629
*   Brife：
*



*/

#include <iostream>
#include <typeinfo>

class Base {
public:
    Base(int data = 10) : a_(data) {}
    virtual ~Base() = default;
    virtual void show() {
        std::cout << "Base::show()" << std::endl;
    }
    virtual void show(int) {
        std::cout << "Base::show(int)" << std::endl;
    }
private:
    int a_;
};

class Derive : public Base {
public:
    Derive(int data = 10) : Base(data), b_(data) {}
    ~Derive() = default;
    // this is override function
    void show(int) {
        std::cout << "Derive::show(int)" << std::endl;
    }
private:
    int b_;
};

int main() {
    Derive d;
    Base* pd = &d;
    pd->show(10);

    std::cout << typeid(pd).name() << std::endl;
    std::cout << typeid(*pd).name() << std::endl;

    return 0;
}