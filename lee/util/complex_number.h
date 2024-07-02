/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：complex_number.h
*   Author：leekaihua
*   Date：20240701
*   Brife：
*



*/
#pragma once

#include <iostream>

namespace lee {
namespace util {

class ComplexNumber {
public:
    ComplexNumber(int real = 1, int imag = 1);
    ComplexNumber(const ComplexNumber& other) = default;
    ComplexNumber& operator=(const ComplexNumber& other) = default;
    ComplexNumber(ComplexNumber&& other) = default;
    ComplexNumber& operator=(ComplexNumber&& other) = default;
    ~ComplexNumber() = default;

    ComplexNumber operator+(const ComplexNumber&) const;
    ComplexNumber operator-(const ComplexNumber&) const;
    ComplexNumber operator*(const ComplexNumber&) const;
    ComplexNumber operator*(double factor) const;
    // postpostion operator ++
    // pass instance copy out, and instance self-increasement by 1
    ComplexNumber operator++(int);
    // prepostion operator ++
    // instance self-increase by 1, and pass out
    ComplexNumber& operator++();
    void operator+=(const ComplexNumber&);

    friend ComplexNumber operator*(double factor, const ComplexNumber& other);
    friend std::istream& operator>>(std::istream& in, ComplexNumber& me);
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& me);

    void report() const;
private:
    double _real;
    double _imag;
};

}
}