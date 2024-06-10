/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_rvalue.cpp
*   Author：leekaihua
*   Date：20240605
*   Brife：
*



*/

#include <iostream>

// this is a global variable, a lvalue definitely.
int i = 0;

int get_value() {
    return i;
}

// val is a lvalue, it has a name
// even though val accept a rvalue such as 6
void set_value(int val) {
    i = val;
}

int main() {
    // compile ok
    int x = get_value();
    std::cout << x << std::endl;
    // compile error, function get_value return a temporary value
    // int x1 = &get_value();
    // 6 is const value, a rvalue
    set_value(6);

    return 0;
}