/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p10.cpp
*   Author：leekaihua
*   Date：2021年12月06日
*   Brife：
*



*/
#include<iostream>
int main(){
    using namespace std;
    double grade[3];
    cout << "Enter 1st grade: " << endl;
    cin >> grade[0];
    cout << "Enter 2nd grade: " << endl;
    cin >> grade[1];
    cout << "Enter 3rd grade: " << endl;
    cin >> grade[2];
    double ave = (grade[0] + grade[1] + grade[2])/3;
    cout << "The average grade is: " << ave << endl;

    return 0;
}