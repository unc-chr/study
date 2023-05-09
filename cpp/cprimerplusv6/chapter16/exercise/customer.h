/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：customer.h
*   Author：leekaihua
*   Date：2023年03月19日
*   Brife：
*



*/
#pragma once
class Customer {
    private:
        long arrive;
        int processtime;
    public:
        Customer() {arrive = processtime = 0;}
        void set(long when);
        long when() const {return arrive;}
        int ptime() const {return processtime;}
};