/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p7.cpp
*   Author：leekaihua
*   Date：2023年03月02日
*   Brife：
*



*/

#include <iostream>

void out_hour_min(int, int);

int main() {
    using namespace std;
    int hours;
    int minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    out_hour_min(hours, minutes);

    return 0;
}

void out_hour_min(int hours, int minutes) {
    using namespace std;
    cout << "Time: " << hours << ":" << minutes << endl;
}