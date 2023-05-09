/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：sale.cpp
*   Author：leekaihua
*   Date：2021年12月31日
*   Brife：
*



*/
#include <iostream>
#include "sale.h"

namespace SALES {
    void setSales(Sales& s, const double ar[], int n) {
        if (n >= 4) {
            n = 4;
        }
        for (int i = 0; i < n; i++) {
            s.sales[i] = ar[i];
        }
        if (n < 4) {
            for (int i = n - 1; i >= n; i--) {
                s.sales[i] = 0;
            }
        }
        calc(s);
    }

    void setSales(Sales& s) {
        using std::cin;
        using std::cout;
        int i = 0;
        while (i < 4) {
            cout << "Enter #" << i + 1 << " sales: ";
            double temp;
            while (!(cin >> temp)) {
                cin.clear();
                while (cin.get() != '\n') {
                    continue;
                }
                cout << "Enter #" << i + 1 << " sales: ";
            }
            s.sales[i] = temp;
            i++;
        }
        calc(s);
    }

    static void calc(Sales& s) {
        double max = s.sales[0];
        double min = s.sales[0];
        double sum = s.sales[0];
        double average = 0;
        for (int i = 1; i < 4; i++) {
            if (s.sales[i] > max) {
                max = s.sales[i];
            }
            if (s.sales[i] < min) {
                min = s.sales[i];
            }
            sum += s.sales[i];
        }
        average = sum/4;
        s.max = max;
        s.min = min;
        s.average = average;
    }

    void showSales(const Sales& s) {
        using std::cout;
        using std::endl;
        cout << "The 4 quarters sales is: ";
        for (int i = 0; i < 4; i++) {
            cout << s.sales[i] << '\t';
        }
        cout << endl;

        cout << "The max sales is " << s.max << endl;
        cout << "The min sales is " << s.min << endl;
        cout << "The average sales is " << s.average << endl;
    }
}