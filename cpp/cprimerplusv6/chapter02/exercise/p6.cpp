/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p6.cpp
*   Author：leekaihua
*   Date：2023年03月02日
*   Brife：
*



*/

#include <iostream>

double convert(double);

int main() {
    using namespace std;
    cout << "Enter the number of light years: ";
    double light_year;
    cin >> light_year;
    double astro_unit = convert(light_year);
    cout << light_year << " light years = " << astro_unit << " astronomical units." << endl;

    return 0;
}

double convert(double astro_unit) {
    return astro_unit * 63240;
}