/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：2023年03月22日
*   Brife：
*



*/

#include <iostream>

int sum_2(int, int);
int sum_value(int, int);

int sum_2(int a, int b) {
    return sum_value(a, b);
}

int sum_value(int a, int b) {
    return a + b;
}

int main() {
    using namespace std;
    cout << sum_value(1, 2) << endl;
    cout << sum_2(1, 2) << endl;

    return 0; 
}