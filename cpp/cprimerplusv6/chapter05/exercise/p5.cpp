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
    int sell[12];
    int sum_sell = 0;

    for (int i = 0; i < 12; i++) {
        cout << month[i] << " sell is: ";
        cin >> sell[i];
    }
    for (int i = 0; i < 12; i++) {
        cout << month[i] << "\t" << sell[i] << endl;
        sum_sell += sell[i];
    }
    cout << "The sum sell amount of this year is " << sum_sell << endl;

    return 0;
}