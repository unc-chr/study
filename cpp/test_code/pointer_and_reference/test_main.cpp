/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_main.cpp
*   Author：leekaihua
*   Date：20240701
*   Brife：
*



*/
// #include <iostream>

// using std::cout;
// using std::endl;

int main() {
    int a = 10;
    int* p_a = &a;
    int& r_a = a;

    a = 20;
    // cout << a << " " << *p_a << " " << r_a << endl;

    *p_a = 30;
    // cout << a << " " << *p_a << " " << r_a << endl;

    r_a = 40;
    // cout << a << " " << *p_a << " " << r_a << endl;
}