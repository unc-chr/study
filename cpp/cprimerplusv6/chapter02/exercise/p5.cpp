/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p5.cpp
*   Author：leekaihua
*   Date：2023年03月02日
*   Brife：
*



*/

#include <iostream>

double convert(double);

int main() {
    using namespace std;
    cout << "PLease enter a Celsius value: ";
    double celsius;
    cin >> celsius;
    double fahrenheit = convert(celsius);
    cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << endl;

    return 0;
}

double convert(double fahtenheit) {
    return 1.8 * fahtenheit + 32.0;
}