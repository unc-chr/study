/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：golf.cpp
*   Author：leekaihua
*   Date：2021年12月31日
*   Brife：
*



*/
#include "golf.h"
#include <cstring>
#include <iostream>

Golf::Golf(const char* fn, int hc) {
    strcpy(fullname, fn);
    m_handicap = hc;
}

Golf::Golf() {
    using std::cin;
    using std::cout;
    char fullname_temp[40];
    int handicap_temp = 0;

    cout << "Enter name: ";
    cin.getline(fullname_temp, 40);
    cout << "Enter handicap: ";
    cin >> handicap_temp;
    cin.get();
    Golf temp(fullname_temp, handicap_temp);
    *this = temp;
}

void Golf::handicap(int hc) {
    m_handicap = hc;
}

void Golf::showgolf() const {
    using std::cout;
    using std::endl;
    cout << "The handicap of " << fullname << " is ";
    cout << m_handicap << endl;
}