/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2021年12月09日
*   Brife：
*



*/
#include<iostream>
#include<cctype>

int main(){
    using namespace std;
    char ch;
    while (cin.get(ch) && ch != '@') {
        if (isdigit(ch)) {
            continue;
        }
        if (islower(ch)) {
            cout << char(ch - 32);
        } else if (isupper(ch)) {
            cout << char(ch + 32);
        } else {
            cout << ch;
        }
    }

    cout << endl;

    return 0;
}