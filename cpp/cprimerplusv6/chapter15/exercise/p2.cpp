/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2023年03月15日
*   Brife：
*



*/
#include "exe_mean.h"
#include <iostream>
#include <cmath>

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
            cout << "Enter next set of numbers <q to quit>: ";
        } catch (Bad_hmean& bg) {
            cout << bg.what() << endl;
            cout << "Try again. Enter two numbers: ";
            continue;
        } catch (Bad_gmean& hg) {
            cout << hg.what() << endl;
            cout << "Sorry, you don't get to play anymore." << endl;
            break;
        }
    }

    cout << "Bye!" << endl;
    return 0;
}

double hmean(double a, double b) {
    if (a == -b) {
        throw Bad_hmean("hmean error. argu a = argu b");
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
    if (a < 0 || b < 0) {
        throw Bad_gmean("gmean error. argu a < 0 or argu b < 0");
    }
    return std::sqrt(a * b);
}