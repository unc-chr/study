/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：time.cpp
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/
#include "mytime.h"
#include <iostream>

Time::Time(int hours, int minutes) {
    m_hours = hours;
    m_minutes = minutes;
}

void Time::add_hours(int hours) {
    m_hours += hours;
}

void Time::add_minutes(int minutes) {
    m_hours += (minutes + m_minutes) / 60;
    m_minutes = (minutes + m_minutes) % 60;
}

void Time::reset(int hours, int minutes) {
    m_hours = hours;
    m_minutes = minutes;
}

void Time::show_time() const {
    std::cout << m_hours << " hours, " << m_minutes << " minutse." << std::endl;
}

Time operator+(const Time& time1, const Time& time2) {
    Time new_time;
    new_time.m_minutes = time1.m_minutes + time2.m_minutes;
    new_time.m_hours = time1.m_hours + time2.m_hours + new_time.m_minutes / 60;
    new_time.m_minutes %= 60;

    return new_time;
}

Time operator-(const Time& time1, const Time& time2) {
    Time diff;
    int tot1, tot2;
    tot1 = time1.m_minutes + time1.m_hours * 60;
    tot2 = time2.m_minutes + time2.m_hours * 60;
    diff.m_hours = (tot2 - tot1) / 60;
    diff.m_minutes = (tot2 - tot1) % 60;
    return diff;
}

Time Time::operator*(double n) const {
    Time result;
    long totalminutes = m_hours * n * 60 + m_minutes * n;
    result.m_hours = totalminutes / 60;
    result.m_minutes = totalminutes % 60;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.m_hours << " hours, " << time.m_minutes << " minutes.";
    return os;
}