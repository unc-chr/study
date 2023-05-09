/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p4.cpp
*   Author：leekaihua
*   Date：2021年12月31日
*   Brife：
*



*/
#include "sale.h"
#include <iostream>

int main(){
    using std::cout;
    using std::endl;
    using namespace SALES;

    double ar[QUARTERS] = {1.234, 2.345, 3.456, 4.567};
    
    Sales A(ar, QUARTERS);
    Sales B;
    A.calc();
    B.calc();
    A.showSales();
    B.showSales();

    return 0;
}