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

class Time {
    private:
        int m_hours;
        int m_minutes;
    public:
        Time(int hours = 0, int minutes = 0);
        void add_hours(int hours);
        void add_minutes(int minutes);
        void reset(int hours = 0, int minutes = 0);
        Time sum(const Time& time) const;
        void show_time() const;
};