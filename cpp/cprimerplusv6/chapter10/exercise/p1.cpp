/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#include <iostream>
#include <string>
#include "bank_account.h"

int main() {
    Bank_Account leekaihua;
    Bank_Account anoy = Bank_Account("anoy", "1234567812345678", 10000);
    leekaihua.show_account();
    leekaihua.deposit(-123);
    leekaihua.deposit(10000);
    leekaihua.withdraw(100000);


    anoy.show_account();
    anoy.deposit(-10000);
    anoy.deposit(100000);
    anoy.withdraw(-10000);
    anoy.withdraw(1000000);
    anoy.withdraw(5000);
}
