/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2022年01月08日
*   Brife：
*



*/
#include "classic2.h"
#include <iostream>
using namespace std;

void Bravo(const Cd& disk);

int main() {
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                            "Alfred Brendel", "Philips", 2, 57.17);

    Cd* pcd = &c1;

    cout << "Using oject directly:\n";
    c1.Report();
    c2.Report();
    cout << endl;

    cout << "Using type cd* pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();
    cout << endl;

    cout << "calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << endl;

    cout << "Testing assignment: " << endl;
    Classic copy;
    copy = c2;
    copy.Report();
    cout << endl;

    return 0;
}

void Bravo(const Cd& disk) {
    disk.Report();
}