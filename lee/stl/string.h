/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：string.h
*   Author：leekaihua
*   Date：20240702
*   Brife：
*



*/
#pragma once

#include <cstring>
#include <iostream>

namespace lee {
namespace stl {

class string {
public:
    string(const char* p = nullptr);
    string(const string& other);
    string& operator=(const string& other);
    string(string&& other);
    string& operator=(string&& other);
    ~string();
    
    string operator+(const string& other) const;
    string operator+(const char* other) const;
    friend string operator+(const char* other, const string& str);
    friend std::ostream& operator<<(std::ostream& os, const string& str);
    bool operator==(const string& other) const;
    bool operator>(const string& other) const;
    bool operator<(const string& other) const;

    // return a reference of char so this char could be changed.
    // syntax like: str[1] = 'a'; char a = str[0];
    char& operator[](size_t pos);
    // return a const ref of char
    // syntax like str[1] = 'a' is forbidden.
    const char& operator[](size_t pos) const;

    size_t length() const;
    size_t size() const;

    const char* c_str() const;

    // class iterator, a nest class in containter
    class iterator {
    public:
        iterator(char* p);
        ~iterator();
        iterator(const iterator& other);
        iterator& operator=(const iterator& other);
        iterator& operator++();
        iterator operator++(int);
        bool operator!=(const iterator& other);
        char& operator*();
    private:
        char* _p;
    };

    iterator begin() const;
    iterator end() const;
private:
    char* _pstr;
};

}
}

namespace lee {
namespace stl {

string::string(const char* p) {
    if (p != nullptr) {
        _pstr = new char[strlen(p) + 1];
        strcpy(_pstr, p);
    } else {
        _pstr = new char[1];
        *_pstr = '\0';
    }
}

string::string(const string& other) {
    _pstr = new char[strlen(other._pstr) + 1];
    strcpy(_pstr, other._pstr);
}

string& string::operator=(const string& other) {
    if (this == &other) {
        return *this;
    }
    delete[] _pstr;

    _pstr = new char[strlen(other._pstr) + 1];
    strcpy(_pstr, other._pstr);
    return *this;
}

string::string(string&& other) {
    _pstr = other._pstr;
    other._pstr = nullptr;
}

string& string::operator=(string&& other) {
    if (this == &other) {
        return *this;
    }
    _pstr = other._pstr;
    other._pstr = nullptr;
    return *this;
}

string::~string() {
    delete[] _pstr;
    _pstr = nullptr;
}

string string::operator+(const string& other) const {
    string temp;
    delete[] temp._pstr;
    temp._pstr = new char[strlen(other._pstr) + strlen(_pstr) + 1];
    strcpy(temp._pstr, _pstr);
    strcpy(temp._pstr + strlen(_pstr), other._pstr);
    return temp;
}

string string::operator+(const char* other) const {
    string temp;
    delete[] temp._pstr;
    temp._pstr = new char[strlen(other) + strlen(_pstr) + 1];
    strcpy(temp._pstr, _pstr);
    strcpy(temp._pstr + strlen(_pstr), other);
    return temp;
}


string operator+(const char* other, const string& str) {
    string temp;
    delete[] temp._pstr;
    temp._pstr = new char[strlen(other) + strlen(str._pstr) + 1];
    strcpy(temp._pstr, other);
    strcpy(temp._pstr + strlen(other), str._pstr);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const string& str) {
    os << str._pstr;
    return os;
}

bool string::operator==(const string& other) const {
    return strcmp(_pstr, other._pstr) == 0;
}

bool string::operator>(const string& other) const {
    return strcmp(_pstr, other._pstr) > 0;
}

bool string::operator<(const string& other) const {
    return strcmp(_pstr, other._pstr) < 0;
}

char& string::operator[](size_t pos) {
    return _pstr[pos];
}

const char& string::operator[](size_t pos) const {
    return _pstr[pos];
}

size_t string::length() const {
    return strlen(_pstr);
}

size_t string::size() const {
    return strlen(_pstr);
}

const char* string::c_str() const {
    return _pstr;
}

string::iterator string::begin() const {
    return iterator(_pstr);
}

string::iterator string::end() const {
    return iterator(_pstr + length());
}

string::iterator::iterator(char* p) {
    _p = p;
}

string::iterator::~iterator() {
}

string::iterator::iterator(const string::iterator& other) {
    _p = other._p;
}

string::iterator& string::iterator::operator=(const string::iterator& other) {
    if (this == &other) {
        return *this;
    }
    _p = other._p;
    return *this;
}

string::iterator& string::iterator::operator++() {
    _p++;
    return *this;
}

string::iterator string::iterator::operator++(int) {
    return iterator(_p++);
}

bool string::iterator::operator!=(const string::iterator& other) {
    return _p != other._p;
}

char& string::iterator::operator*() {
    return *_p;
}

}
}