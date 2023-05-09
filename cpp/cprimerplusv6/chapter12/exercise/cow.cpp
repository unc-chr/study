/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：cow.cpp
*   Author：leekaihua
*   Date：2022年01月05日
*   Brife：
*



*/
#include "cow.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

Cow::Cow() {
    cout << "This is default constructor function." << endl;
    strcpy(name, "leekaihua");
    hobby = new char[7];
    strcpy(hobby, "coding");
    weight = 75;
    cout << "Default constructor function end." << endl;
}

Cow::Cow(const char* nm, const char* ho, double wt) {
    cout << "This is constructor function." << endl;
    strcpy(name, nm);
    int length = strlen(ho);
    hobby = new char[length + 1];
    strcpy(hobby, ho);
    weight = wt;
    cout << "Constructor function end." << endl;
}

Cow::Cow(const Cow& c) {
    cout << "This is copy constructor function." << endl;
    weight = c.weight;
    strcpy(name, c.name);
    int length = strlen(c.hobby);
    hobby = new char[length + 1];
    strcpy(hobby, c.hobby);
    cout << "Copy constructor function end." << endl;
}

Cow::~Cow() {
    delete [] hobby;
    cout << name << " object deleted!" << endl;
}

Cow& Cow::operator=(const Cow& c) {
    cout << "This is = constructor function." << endl;
    if (this == &c) {
        return *this;
    }
    delete [] hobby;
    strcpy(this->name, c.name);
    strcpy(this->hobby, c.hobby);
    this->weight = c.weight;
    cout << "= constructor function end." << endl;
    return *this;
}

void Cow::ShowCow() const {
    cout << name << "'s hobby is " << hobby;
    cout << ", weight is " << weight << endl;
}