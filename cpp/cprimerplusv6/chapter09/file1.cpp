/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：file1.cpp
*   Author：leekaihua
*   Date：2021年12月29日
*   Brife：
*



*/
#include <iostream>
#include "coordin.h"
using namespace std;
int main(){
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quie): ";
    }

    cout << "Bye!\n";

    return 0;
}