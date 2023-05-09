/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p4.cpp
*   Author：leekaihua
*   Date：2023年03月03日
*   Brife：
*



*/

#include <iostream>

const int day_to_hour = 24;
const int hour_to_min = 60;
const int min_to_sec = 60;
const int day_to_seconds = 86400;
const int hour_to_seconds = 3600;

void convert(long seconds);

int main() {
    using namespace std;
    cout << "Enter the number of seconds: ";
    long seconds;
    cin >> seconds;
    convert(seconds);

    return 0;
}

void convert(long seconds) {
    using namespace std;
    long left = seconds;
    // long day = left/(day_to_hour * hour_to_min * min_to_sec);
    // left = left%(day_to_hour * hour_to_min * min_to_sec);
    long day = left/day_to_seconds;
    left = left%day_to_seconds;
    // long hours = left/(hour_to_min * min_to_sec);
    // left = left%(hour_to_min * min_to_sec);
    long hours = left/hour_to_seconds;
    left = left%hour_to_seconds;
    long minutes = left/min_to_sec;
    long sec = left%min_to_sec;
    cout << seconds << " seconds = "
        << day << " days, "
        << hours << " hours, "
        << minutes << " minutes, "
        << sec << " seconds"
        << endl;
}