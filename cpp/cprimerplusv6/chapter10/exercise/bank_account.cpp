/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：bank_account.cpp
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#include <iostream>
#include <string>
#include "bank_account.h"

Bank_Account::Bank_Account() {
    m_owner_name = "leekaihua";
    m_account = "0000000000000000";
    m_balance = 100000000;
};

Bank_Account::Bank_Account(
    const std::string& owner_name,
    const std::string& account,
    double balance
) {
    m_owner_name = owner_name;
    m_account = account;
    m_balance = balance;
};

void Bank_Account::show_account() const {
    using std::cout;
    using std::endl;
    cout << m_owner_name << " accout: ";
    cout << m_account << " balance is ";
    cout << m_balance << "!" << endl;
}

void Bank_Account::deposit(double cash) {
    using std::cout;
    using std::endl;
    if (cash < 0) {
        cout << "Number of deposit can't be negative!";
        cout << " Transaction is aborted!" << endl;
    } else {
        m_balance += cash;
        show_account();
    }
}

void Bank_Account::withdraw(double cash) {
    using std::cout;
    using std::endl;
    if (cash < 0) {
        cout << "Number of withdraw can't be negative!";
        cout << " Transaction is aborted!" << endl;
    } else if (cash > m_balance) {
        cout << "Number of withdraw more than your balance!";
        cout << " Transaction is aborted!" << endl;
    } else {
        m_balance -= cash;
        show_account();
    }
}