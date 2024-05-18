/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#include "wine2.h"
#include "pairs.h"
#include <iostream>

int main() {
    using std::cin;
    using std::endl;
    using std::cout;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);
    holding.Getbottles();
    holding.show_wine();

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};

    Wine more("Gushing Grape Red", YRS, y, b);
    more.show_wine();
    cout << "Total bottles for " << more.Label()
        << ": " << more.sum() << endl;

    cout << "Bye!" << endl;

    return 0;
}