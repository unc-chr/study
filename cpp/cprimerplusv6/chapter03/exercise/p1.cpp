/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2023年03月03日
*   Brife：
*



*/

#include <iostream>

const int foot_to_inch = 12;

int main() {
    using namespace std;

    cout << "Enter your height: ______\b\b\b\b\b\b";
    int inch;
    cin >> inch;
    int new_foot = inch/foot_to_inch;
    int new_inch = inch%foot_to_inch;
    cout << "Your height " << inch << " inches is "
        << new_foot << " foots and " << new_inch << " inches." << endl;

    return 0;
}