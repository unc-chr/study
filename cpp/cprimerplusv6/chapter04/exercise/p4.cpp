/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2021年12月06日
*   Brife：
*



*/
#include<iostream>
#include<string>

int main(){
    using namespace std;
    string first_name;
    string last_name;

    cout << "Enter your first name: " << endl;
    getline(cin, first_name);
    cout << "Enter your last name: " << endl;
    getline(cin, last_name);
    
    string name = first_name + ", " + last_name;
    cout << "Here's the information in a single string: ";
    cout << name << endl;

    return 0;
}