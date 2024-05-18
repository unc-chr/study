/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：stringbad.cpp
*   Author：leekaihua
*   Date：2022年01月03日
*   Brife：
*



*/
#include "string1.h"
#include <cstring>
using std::cin;
using std::cout;

int String::num_string = 0;

int String::HowMany() {
    return num_string;
}

String::String(const char* s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_string++;
}

String::String() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_string++;
}

String::String(const String& st) {
    num_string++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

String::~String() {
    --num_string;
    delete [] str;
}

String& String::operator=(const String& st) {
    if (this == &st) {
        return *this;
    }
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String& String::operator=(char* s) {
    delete [] str;
    len = std::strlen(st);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char& String::operator[](int i) {
    return str[i];
}

const char& String::operator[](int i) const {
    return str[i];
}

bool operator<(const String& st1, const String& st2) {
    return (std::strcmp(st1.str, st2,str) < 0);
}

bool operator>(const String& st1, const String& st2) {
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2) {
    return (std::strcmp(st1,str, st2,str) == 0);
}

std::ostream& operator<<(std::ostream& os, const String& st) {
    os << st.str;
    return os;
}

std::istream& operator>>(istream& is, String& st) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) {
        st = temp;
    }
    while (is && is.get() != '\n') {
        continue;
    }

    return is;
}