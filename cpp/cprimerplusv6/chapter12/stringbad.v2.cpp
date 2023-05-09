/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：stringbad.cpp
*   Author：leekaihua
*   Date：2022年01月03日
*   Brife：
*



*/
#include "stringbad.h"
#include <cstring>

using std::cout;

int StringBad::num_string = 0;

StringBad::StringBad(const char* s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_string++;
    cout << num_string << ": \"" << str
        << " object created\n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_string++;
    cout << num_string << ": \"" << str
        << " default object created\n";
}

StringBad::~StringBad() {
    cout << "\"" << str << "\" object deleted.";
    --num_string;
    cout << num_string << " left\n";
    delete [] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st) {
    os << st.str;
    return os;
}

StringBad::StringBad(const StringBad& st) {
    num_string++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << num_string << ": \"" << str
        << " object created\n";
}

StringBad& StringBad::operator=(const StringBad& st) {
    if (this == &st) {
        return *this;
    }
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << num_string << ": \"" << str
        << " object copied\n";
}