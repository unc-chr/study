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
    class Sales {
        private:
            double sales [QUARTERS];
            double average;
            double max;
            double min;
        public:
            Sales(const double ar[], int n);
            Sales();
            void showSales();
            void calc();
    };
}