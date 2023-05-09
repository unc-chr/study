/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：complex0.h
*   Author：leekaihua
*   Date：2022年01月03日
*   Brife：
*



*/
#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class complex {
    private:
        double real;
        double imaginary;
    public:
        complex() {real = 0.0, imaginary = 0.0;}
        complex(double p_real, double p_imaginary);
        ~complex(){};
        double real_val();
        double ima_val();
        complex operator+(const complex& a) const;
        complex operator-(const complex& a) const;
        complex operator*(const complex& a) const;
        complex operator*(double x) const;
        friend complex operator~(const complex& a);
        friend complex operator*(double x, const complex& a);
        friend std::ostream& operator<<(std::ostream& os, const complex& a);
        friend std::istream& operator>>(std::istream& is, complex& a);
};

#endif