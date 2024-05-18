/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p10.cpp
*   Author：leekaihua
*   Date：2021年12月07日
*   Brife：
*



*/
#include<iostream>
int main(){
    using namespace std;
    int num_row;
    cout << "Enter number of rows: ";
    cin >> num_row;

    // for (int i = 0; i < num_row; i++) {
    //     for (int j = 0; j < num_row - i - 1; j++) {
    //         cout << ".";
    //     }
    //     for (int k = 0; k < i + 1; k++) {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= num_row; i++) {
        for (int j = 1; j <= num_row - i; j++) {
            cout << ".";
        }
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}