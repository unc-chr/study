/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：sale.h
*   Author：leekaihua
*   Date：2021年12月31日
*   Brife：
*



*/
#pragma once

namespace SALES {
    const int QUARTERS = 4;
    struct Sales {
        double sales [QUARTERS];
        double average;
        double max;
        double min;
    };
    void setSales(Sales& s, const double ar[], int n);
    void setSales(Sales& s);
    void showSales(const Sales& s);
    static void calc(Sales&);
}