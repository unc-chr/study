/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#include <iostream>
#include "person.h"

int main() {
    using std::cout;
    using std::endl;

    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    one.FormalShow();
    cout << endl;

    two.Show();
    two.FormalShow();
    cout << endl;

    three.Show();
    three.FormalShow();
    cout << endl;

    cout << "Bye!" << endl;
    return 0;
}