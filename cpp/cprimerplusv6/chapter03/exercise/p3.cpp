/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2023年03月03日
*   Brife：
*



*/

#include <iostream>

const int deg_to_min = 60;
const int min_to_sec = 60;

double arc_combine (double, double, double);

int main() {
    using namespace std;
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    
    cout << "First, enter the degrees: ";
    int degrees;
    cin >> degrees;

    cout << "Next, enter the minutes of arc: ";
    int minutes;
    cin >> minutes;

    cout << "Finally, enter the seconds of arc: ";
    int seconds;
    cin >> seconds;

    double new_degrees = arc_combine(degrees, minutes, seconds);
    cout << degrees << " degrees, "
        << minutes << " minutes, "
        << seconds << " seconds = "
        << new_degrees << " degrees"
        << endl;

    return 0;
}

double arc_combine(double degrees, double minutes, double seconds) {
    double min_to_deg = minutes/deg_to_min;
    double sec_to_deg = seconds/deg_to_min/min_to_sec;
    return degrees + min_to_deg + sec_to_deg;
}