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
#include<cstring>

int main(){
    using namespace std;
    char first_name[20];
    char last_name[20];

    cout << "Enter your first name: " << endl;
    cin.getline(first_name, 20);
    cout << "Enter your last name: " << endl;
    cin.getline(last_name, 20);
    
    char name[40] = {};
    strcat(name, first_name);
    strcat(name, ", ");
    strcat(name, last_name);

    cout << "Here's the information in a single string: ";
    cout << name << endl;

    return 0;
}