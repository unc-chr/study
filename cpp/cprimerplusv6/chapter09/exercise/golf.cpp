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

void setgolf(golf& g, const char* name, int hc) {
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf& g) {
    using std::cin;
    using std::cout;

    cout << "Enter name: ";
    cin.getline(g.fullname, 40);
    if (g.fullname[0] == '\0') {
        return 0;
    }

    cout << "Enter handicap: ";
    cin >> g.handicap;
    cin.get();
    return 1;
}

void handicap(golf&g, int hc) {
    g.handicap = hc;
}

void showgolf(const golf& g) {
    using std::cout;
    using std::endl;
    cout << "The handicap of " << g.fullname << " is ";
    cout << g.handicap << endl;
}