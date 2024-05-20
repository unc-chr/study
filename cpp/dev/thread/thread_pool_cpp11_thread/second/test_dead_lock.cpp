/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_dead_lock.cpp
*   Author：leekaihua
*   Date：2024年04月28日
*   Brife：
*



*/
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <string>

class BankAccount {
    private:
        double balance;
        std::string name;
    public:
        std::mutex mx;
    public:
        BankAccount() : balance(0), name("unknown") {}
        BankAccount(double value, std::string v_name) : balance(value), name(v_name) {}
        bool withdraw(double value);
        bool deposit(double value);
        void transfer(BankAccount& to, double value);
};

bool BankAccount::withdraw(double value) {
    if (balance >= value) {
        balance -= value;
        return true;
    } else {
        return false;
    }
}

bool BankAccount::deposit(double value) {
    balance += value;
    return true;
}

void BankAccount::transfer(BankAccount& to, double value) {
    mx.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (withdraw(value)) {
        to.mx.lock();
        to.deposit(value);
        std::cout << "source_name: " << name
                << ", source_val: " << balance
                << ", dest_name: " << to.name
                << ", dest_value: " << to.balance
                << std::endl;        
        to.mx.unlock();
    }
    mx.unlock();
    return;
}

void transfer(BankAccount& from, BankAccount& to, double value) {
    from.transfer(to, value);
}

int main() {
    BankAccount a(1000, "a");
    BankAccount b(500, "b");
    std::thread t1(transfer, std::ref(a), std::ref(b), 500);
    std::thread t2(transfer, std::ref(b), std::ref(a), 500);
    t1.join();
    t2.join();

    return 0;
}