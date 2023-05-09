/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p5.cpp
*   Author：leekaihua
*   Date：2021年12月07日
*   Brife：
*



*/
#include<iostream>
int main(){
    using namespace std;
    char * month[12] = {"January", "February", "March",
        "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};
    int sell[3][12];
    int sum_sell = 0;
    int sum_sell_year = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 12; j++) {
            cout << "Year " << i << " " << month[j] << " sell is: ";
            cin >> sell[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 12; j++) {
            cout << sell[i][j] << " ";
            sum_sell_year += sell[i][j];
        }
        cout << endl;
        cout << "Year " << i << " sell amount is: " << sum_sell_year << endl;
        sum_sell += sum_sell_year;
        sum_sell_year = 0;
    }
    cout << "The sum sell amount of 3 year is " << sum_sell << endl;

    return 0;
}