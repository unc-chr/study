/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_virtual_private_func.cpp
*   Author：leekaihua
*   Date：20240629
*   Brife：
*



*/

#include <iostream>

using std::cout;
using std::endl;

class Base {
public:
    Base() = default;
    virtual void show() {
        cout << "Base::show()" << endl;
    }
};

class Derive : public Base {
public:
    Derive() = default;
private:
    void show() {
        cout << "Derive::show()" << endl;
    }
};

int main() {
    Derive d;
    Base* p = &d;
    // question: could this command go through compile?
    // Yes! Compile OK. And run show: Derive::show()
    p->show();

    return 0;
}