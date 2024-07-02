/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：complex_number.cpp
*   Author：leekaihua
*   Date：20240701
*   Brife：
*



*/
#include "complex_number.h"

#include <iostream>

using std::cout;
using std::endl;

namespace lee {
namespace util {

ComplexNumber::ComplexNumber(int real, int imag)
        : _real(real)
        , _imag(imag) {
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber(_real + other._real, _imag + other._imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber(_real - other._real, _imag - other._imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    return ComplexNumber(
        _real * other._real - _imag * other._imag,
        _real * other._imag + _imag * other._real);
}

ComplexNumber ComplexNumber::operator*(double factor) const {
    return ComplexNumber(_real * factor, _imag * factor);
}

// postpostion operator ++
ComplexNumber ComplexNumber::operator++(int) {
    // ComplexNumber temp(_real, _imag);
    // ++_real;
    // ++_imag;
    // return temp;
    return ComplexNumber(_real++, _imag++);
}

// prepostion operator ++
ComplexNumber& ComplexNumber::operator++() {
    ++_real;
    ++_imag;
    return *this;
}

void ComplexNumber::operator+=(const ComplexNumber& other) {
    _real += other._real;
    _imag += other._imag;
}

// friend function used for double * ComplexNumber
ComplexNumber operator*(double factor, const ComplexNumber& other) {
    return ComplexNumber(other._real * factor, other._imag * factor);
}

// friend function used for cin >> ComplexNumber
std::istream& operator>>(std::istream& in, ComplexNumber& me) {
    std::cout << "input complex real: ";
    in >> me._real;
    std::cout << "input complex imag: ";
    in >> me._imag;
    return in;
}

// friend function used for cout << ComplexNumber
std::ostream& operator<<(std::ostream& os, const ComplexNumber& me) {
    os << "complex number: " << me._real << "+" << me._imag << "i" << endl;
    return os;
}

void ComplexNumber::report() const {
    cout << "complex number: " << _real << "+" << _imag << "i" << endl;
}

}
}