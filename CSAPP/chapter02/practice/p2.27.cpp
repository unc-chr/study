/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p2.27.cpp
*   Author：leekaihua
*   Date：2023年09月12日
*   Brife：
*



*/

#include <iostream>

int uadd_ok(unsigned int x, unsigned int y);
void test_unsigned_int_overflow();

using std::cout;
using std::endl;

int main() {
    test_unsigned_int_overflow();
    return 0;
}

void test_unsigned_int_overflow() {
    unsigned int a, b;
    a = 2147483650;
    b = 2147483650;
    unsigned int result = uadd_ok(a, b);
    cout << a << ", " << b << ", " << result << endl;
}

int uadd_ok(unsigned int x, unsigned int y) {
    unsigned int result = x + y;
    cout << "result: " << result << endl;
    if (result < x || result < y) {
        return 0;
    } else {
        return 1;
    }
}