/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB5.cpp
*   Author：leekaihua
*   Date：2023年04月28日
*   Brife：
*



*/

#include <iostream>
using namespace std;

int main() {
    string a;
    cin >> a;
    if (a == "") {
        cout << a << endl;
        return 0;
    }
    string b;
    b = a[0];
    cout << "b: " << b << endl;
    for (int i = 1; i < a.length(); i++) {
        if (a[i] != a[i - 1]) {
            b += a[i];
            cout << "b: " << b << endl;
        }
    }
    cout << b << endl;

    return 0;
}

