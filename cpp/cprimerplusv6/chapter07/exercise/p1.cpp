/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2021年12月15日
*   Brife：
*



*/
#include<iostream>

double re_ave(double x, double y);

int main(){
    using namespace std;
    double x;
    double y;
    cout << "Enter two number: ";
    while (cin >> x >> y) {
        if (x == 0 || y == 0) {
            break;
        }
        double result = re_ave(x, y);
        cout << "result of x: " << x << " and y: " << y;
        cout << " is: " << result << endl;
        cout << "Enter another two number: ";
    }

    return 0;
}

double re_ave(double x, double y) {
    double result = 2 * x * y/(x + y);
    return result;
}