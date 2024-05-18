/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：2021年12月08日
*   Brife：
*



*/
#include<iostream>
int main(){
    using namespace std;
    cout << "Enter a character: ";
    char ch;
    cin.get(ch);
    cin.get();

    cout << "ch+1: ";
    cout << ch + 1 << endl;
    cout << "ch++: ";
    cout << ++ch << endl;
    // int x = 10;
    // cout << !!x << endl;

    return 0;
}