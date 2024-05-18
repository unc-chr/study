/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB28.cpp
*   Author：leekaihua
*   Date：2023年05月02日
*   Brife：
*



*/

#include <iostream>
using namespace std;

long long fast_pow(long long a, int b, int p) {
    long long result = 1;
    a %= p;
    cout << "a: " << a << endl;
    while (b) {
        if (b & 1) {
            result = (result * a) % p;
        }
        b >>= 1;
        a = (a * a) % p;
        cout << "result: " << result << ", a: " << a << ", b: " << b << endl;
    }

    return result;
}

int main() {
    int count;
    cin >> count;
    int a, b, p;
    while (count--) {
        cin >> a >> b >> p;
        long long result = fast_pow(a, b, p);
        cout << result << endl;
    }

    return 0;
}