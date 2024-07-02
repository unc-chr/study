/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：20240629
*   Brife：
*



*/
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Base {
public:
    Base() {
        cout << "Base constructor." << endl;
        clear();
    }
    // this clear function set all memory to zero, including
    // virtual function table pointer, so dyamic binding can't
    // access virtual function table.
    void clear() {
        memset(this, 0, sizeof(*this));
    }
    virtual void show() {
        cout << "call Base::show()" << endl;
    }
};

class Derive : public Base {
public:
    Derive() {
        cout << "Derive constructor." << endl;
    }
    void show() {
        cout << "call Derive::show()" << endl;
    }
};

int main() {
    // these commands compile and run OK?
    // compile OK. run corrupt at p1->show()
    // Base* p1 = new Base();
    // p1->show();
    // delete p1;

    // these commands compile and run OK?
    // compile OK. run OK
    Base* p2 = new Derive();
    p2->show();
    delete p2;

    return 0;
}