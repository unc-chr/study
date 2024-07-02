/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_virtual_base_class.cpp
*   Author：leekaihua
*   Date：20240630
*   Brife：
*



*/
#include <iostream>

using std::cout;
using std::endl;

class A {
public:
    virtual void func() {
        cout << "call A::func" << endl;
    }
    void operator delete(void* ptr) {
        cout << "operator delete p: " << ptr << endl;
        free(ptr);
    }
private:
    int a_;
};

class B : virtual public A {
public:
    void func() {
        cout << "call B::func" << endl;
    }
    void* operator new(size_t size) {
        void* p = malloc(size);
        cout << "operator new p :" << p << endl;
        return p;
    }
private:
    int b_;
};

int main() {
    A* p = new B();
    p->func();
    delete p;

    return 0;
}