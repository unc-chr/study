/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2023年03月15日
*   Brife：
*



*/
#include "exe_mean_for_p3.h"
#include <iostream>
#include <cmath>
#include <typeinfo>

double hmean(double a, double b);
double gmean(double a, double b);

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
            cout << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        } catch (Bad_mean& bg) {
            cout << "Now processing type " << typeid(bg).name() << "." << endl;
            cout << bg.what() << endl;
            bg.report();
            cout << "Sorry, you don't get to play anymore." << endl;
            break;
        }
    }

    cout << "Bye!" << endl;
    return 0;
}

double hmean(double a, double b) {
    if (a == -b) {
        throw Bad_hmean("a hmean error. argu a = argu b", a, b);
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
    if (a < 0 || b < 0) {
        throw Bad_gmean("a gmean error. argu a < 0 or argu b < 0", a, b);
    }
    return std::sqrt(a * b);
}