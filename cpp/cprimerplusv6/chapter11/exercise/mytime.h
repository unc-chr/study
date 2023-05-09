/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：time.h
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/
#pragma once

#include <iostream>

class Time {
    private:
        int m_hours;
        int m_minutes;
    public:
        Time(int hours = 0, int minutes = 0);
        void add_hours(int hours);
        void add_minutes(int minutes);
        void reset(int hours = 0, int minutes = 0);
        void show_time() const;

        // Time operator+(const Time& time) const;
        friend Time operator+(const Time& time1, const Time& time2);
        // Time operator-(const Time& time) const;
        friend Time operator-(const Time& time1, const Time& time2);
        Time operator*(double n) const;
        friend Time operator*(double n, const Time& time) { return time * n;};
        friend std::ostream& operator<<(std::ostream& os, const Time& time);
};
