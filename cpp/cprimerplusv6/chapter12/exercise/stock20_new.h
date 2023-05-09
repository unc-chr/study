/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：stock20.h
*   Author：leekaihua
*   Date：2023年03月11日
*   Brife：
*



*/
#pragma once
#include <iostream>

class Stock {
    private:
        char* company;
        int shares;
        double share_val;
        double total_val;
        void set_tot() {total_val = shares * share_val;};
    public:
        Stock();
        // Stock(const std::string& co, long n = 0, double pr = 0.0);
        Stock(const char* co, long n = 0, double pr = 0.0);
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show() const;
        const Stock& topval(const Stock& s) const;

        friend std::ostream& operator<<(std::ostream& os, const Stock& s);
};