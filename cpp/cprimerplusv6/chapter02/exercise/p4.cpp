/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p4.cpp
*   Author：leekaihua
*   Date：2023年03月02日
*   Brife：
*



*/

#include <iostream>

int convert(int);

int main() {
    using namespace std;
    cout << "Enter your age: ";
    int age;
    cin >> age;
    int monthes = convert(age);
    cout << "Your age " << age << " includes " << monthes << " monthes." << endl;

    return 0;
}

int convert(int age) {
    return age * 12;
}