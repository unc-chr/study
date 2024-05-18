/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：bank_account.h
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#pragma once
#include <string>

class Bank_Account {
    private:
        std::string m_owner_name;
        std::string m_account;
        double m_balance;

    public:
        Bank_Account();
        Bank_Account(
            const std::string& owner_name,
            const std::string& account,
            double balance 
        );
        void show_account() const;
        void deposit(double cash);
        void withdraw(double cash);
};
