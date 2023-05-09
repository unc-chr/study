/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：Person.cpp
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#include <iostream>
#include <cstring>
#include <string>
#include "person.h"

Person::Person(const std::string& ln, const char* fn) {
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const {
    using std::cout;
    using std::endl;
    cout << "Person name: " << fname << " " << lname << endl;
}

void Person::FormalShow() const {
    using std::cout;
    using std::endl;
    cout << "Person Formal Name: " << lname << " " << fname << endl;
}