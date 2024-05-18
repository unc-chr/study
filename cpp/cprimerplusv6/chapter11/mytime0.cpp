/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：time.cpp
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/
#include "mytime0.h"
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

Time Time::sum(const Time& time) const {
    Time new_time;
    new_time.add_hours(time.m_hours);
    new_time.add_hours(this->m_hours);
    new_time.add_minutes(time.m_minutes);
    new_time.add_minutes(this->m_minutes);

    return new_time;
}

void Time::show_time() const {
    std::cout << m_hours << " hours, " << m_minutes << " minutse." << std::endl;
}
