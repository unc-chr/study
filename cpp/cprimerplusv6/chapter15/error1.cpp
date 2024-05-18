/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：error1.cpp
*   Author：leekaihua
*   Date：2022年01月16日
*   Brife：
*



*/
#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main() {
    double x, y, z;

    std::cout << "Enter two number: ";
    while (std::cin >> x >> y) {
        z = hmean(x, y);
        std::cout << "Harmonic mean of " << x << " and " << y
            << " is " << z << std::endl;
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) {
    if (a == -b) {
        std::cout << "untenable arguments to hmean()\n";
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}