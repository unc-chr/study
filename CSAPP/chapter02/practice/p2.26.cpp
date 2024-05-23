/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p2.26.cpp
*   Author：leekaihua
*   Date：2023年09月12日
*   Brife：
*



*/

#include <iostream>

int main() {
    using namespace std;

    unsigned int a = 5;
    unsigned int b = 6;
    unsigned int result = a - b;
    if (a - b < 0) {
        cout << "<" << endl;
    } else {
        cout << ">=" << endl;
    }
    cout << result << endl;

    return 0;
}