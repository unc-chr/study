/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2021年12月09日
*   Brife：
*



*/
#include<iostream>
int main(){
    using namespace std;
    double double_array[10];
    int i = 0;
    double sum = 0;
    while (i < 10 && cin >> double_array[i]) {
        sum += double_array[i];
        i++;
    }
    double ave = sum/i;
    int num_large = 0;
    for (int j = 0; j <= i; j++) {
        if (double_array[j] > ave) {
            num_large++;
        }
    }

    cout << "The sum of input num is: " << sum << endl;
    cout << "The average of input num is: " << ave << endl;
    cout << "And there is " << num_large << " number less than average." << endl;

    return 0;
}