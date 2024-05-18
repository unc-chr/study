/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2021年12月06日
*   Brife：
*



*/
#include<iostream>
#include<string>

int main(){
    using namespace std;

    cout << "What is your first name?" << endl;
    string first_name;
    getline(cin, first_name);    

    cout << "What is your last name?" << endl;
    string last_name;
    getline(cin, last_name);    

    cout << "What letter grade do you deserve?" << endl;
    char grade;
    cin >> grade;
    cin.get();
    grade = grade + 1;

    cout << "What is your age?" << endl;
    string age;
    getline(cin, age);    

    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;

    return 0;
}