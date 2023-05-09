/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2021年12月06日
*   Brife：
*



*/
#include<iostream>
#include<string>

int main(){
    using namespace std;
    cout << "Enter you name:\n";
    string name;
    getline(cin, name);

    string dessert;
    cout << "Enter you favorite dessert:\n";
    getline(cin, dessert);

    cout << "I have some delicious " << dessert;
    cout << "for you, " << name << ".\n";

    return 0;
}