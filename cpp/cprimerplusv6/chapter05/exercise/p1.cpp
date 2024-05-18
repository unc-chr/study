/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2021年12月07日
*   Brife：
*



*/
#include<iostream>

int main(){
    using namespace std;
    cout << "Enter num 1: ";
    int num1;
    cin >> num1;

    cout << "Enter num 2: ";
    int num2;
    cin >> num2;

    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    int sum = 0;
    for (int i = num1; i <= num2; i++) {
        sum += i;
    }
    cout << "sum from " << num1 << " to " << num2 << " is " << sum << endl;

    return 0;
}