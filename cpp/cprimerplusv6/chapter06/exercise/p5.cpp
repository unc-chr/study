/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p5.cpp
*   Author：leekaihua
*   Date：2021年12月09日
*   Brife：
*



*/
#include<iostream>
int main(){
    using namespace std;
    int earn;
    double tax;
    cout << "Enter you earn: ";
    while (cin >> earn) {
        if (earn < 0) {
            break;
        }
        if (earn <= 5000) {
            tax = 0;
        } else if (earn > 5000 && earn < 15000) {
            tax = (earn - 5000) * 0.1;
        } else if (earn >= 15000 && earn < 35000) {
            tax = 1000 + (earn - 15000) * 0.15;
        } else {
            tax = 1000 + 3000 + (earn - 35000) * 0.2;
        }
        cout << tax << endl;
        cout << "Enter your next earn: ";
    }

    return 0;
}