/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2021年12月07日
*   Brife：
*



*/
#include<iostream>
int main(){
    using namespace std;
    cout << "Enter a num, 0 to quit: ";
    int sum = 0;
    int input;
    cin >> input;
    while (input != 0) {
        sum += input;
        cout << "The sum is " << sum << " so far!" << endl;
        cin >> input;
    }

    return 0;
}