/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：usestock2.cpp
*   Author：leekaihua
*   Date：2023年03月11日
*   Brife：
*



*/
#include "stock20.h"
#include <iostream>

const int STKS = 4;
int main() {
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++) {
        stocks[st].show();
    }

    const Stock* top = &stocks[0];
    for (st = 1; st < STKS; st++) {
        top = &top->topval(stocks[st]);
    }

    std::cout << "\nMost Valuable holding:\n";
    top->show();

    std::cout << "test_nullptr out:" << std::endl;
    top->test_nullptr1();
    top->test_nullptr2();

    std::cout << "test_nullptr out with nullptr:" << std::endl;
    const Stock* test_stock = nullptr;
    test_stock->test_nullptr1();
    test_stock->test_nullptr2();

    return 0;
}