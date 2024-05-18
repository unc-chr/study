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
    Sales::Sales(const double ar[], int n) {
        if (n >= 4) {
            n = 4;
        }
        for (int i = 0; i < n; i++) {
            sales[i] = ar[i];
        }
        if (n < 4) {
            for (int i = n - 1; i >= n; i--) {
                sales[i] = 0;
            }
        }
    }

    Sales::Sales() {
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
            sales[i] = temp;
            i++;
        }
    }

    void Sales::calc() {
        double tmp_max = sales[0];
        double tmp_min = sales[0];
        double sum = sales[0];
        for (int i = 1; i < 4; i++) {
            if (sales[i] > tmp_max) {
                tmp_max = sales[i];
            }
            if (sales[i] < tmp_min) {
                tmp_min = sales[i];
            }
            sum += sales[i];
        }
        max = tmp_max;
        min = tmp_min;
        average = sum/4;
    }

    void Sales::showSales() {
        using std::cout;
        using std::endl;
        cout << "The 4 quarters sales is: ";
        for (int i = 0; i < 4; i++) {
            cout << sales[i] << '\t';
        }
        cout << endl;

        cout << "The max sales is " << max << endl;
        cout << "The min sales is " << min << endl;
        cout << "The average sales is " << average << endl;
    }
}