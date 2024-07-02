/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_diamond_inheritance.cpp
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
    A(int data) : a_(data) {cout << "A::A()" << endl;}
    ~A() {cout << "A::~A()" << endl;}
private:
    int a_;
};

class B : public A {
public:
    B(int data) : A(data), b_(data) {cout << "B::B()" << endl;}
    ~B() {cout << "B::~B()" << endl;}
protected:
    int b_;
};

class C : public A {
public:
    C(int data) : A(data), c_(data) {cout << "C::C()" << endl;}
    ~C() {cout << "C::~C()" << endl;}
protected:
    int c_;
};

class D : public B, public C {
public:
    D(int data) : B(data), C(data), d_(data) {cout << "D::D()" << endl;}
    ~D() {cout << "D::~D()" << endl;}
protected:
    int d_;
};

int main() {
    D d(10);
    return 0;
}