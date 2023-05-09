/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：complex0.cpp
*   Author：leekaihua
*   Date：2022年01月03日
*   Brife：
*



*/
#include "complex0.h"

complex::complex(double p_real, double p_imaginary) {
    real = p_real;
    imaginary = p_imaginary;
}

double complex::real_val() {
    return real;
}

double complex::ima_val() {
    return imaginary;
}

complex complex::operator+(const complex& a) const {
    return complex(real + a.real, imaginary + a.imaginary);
}

complex complex::operator-(const complex& a) const {
    return complex(real - a.real, imaginary - a.imaginary);
}

complex complex::operator*(const complex& a) const {
    double new_real = real * a.real - imaginary * a.imaginary;
    double new_ima = real * a.imaginary + imaginary * a.real;
    return complex(new_real, new_ima);
}

complex complex::operator*(double x) const {
    return complex(real * x, imaginary * x);
}

complex operator~(const complex& a) {
    return complex(a.real, -a.imaginary);
}

complex operator*(double x, const complex& a) {
    return a * x;
}

std::ostream& operator<<(std::ostream& os, const complex& a) {
    os << "(" << a.real << ", " << a.imaginary << ")";
    return os;
}

std::istream& operator>>(std::istream& is, complex& a) {
    using std::cout;
    cout << "Enter real: ";
    is >> a.real;
    cout << "Enter imaginary: ";
    is >> a.imaginary;
    return is;
}