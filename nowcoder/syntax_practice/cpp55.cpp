/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：cpp55.cpp
*   Author：leekaihua
*   Date：2023年03月30日
*   Brife：
*



*/

#include <cstddef>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string toHexString(int n);

int main() {

    int n;
    cin >> n;

    string hexStr = toHexString(n);
    cout << hexStr << endl;

    return 0;
}

string toHexString(int n) {
    // write your code here......
    string str_hex;
    int rem = n;
    stack<int> hex_num;
    while (n != 0) {
        rem = n % 16;
        n = n / 16;
        hex_num.push(rem);
    }
    int digit;
    while (!hex_num.empty()) {
        digit = hex_num.top();
        hex_num.pop();
        if (digit < 10) {
            str_hex += char(digit + '0');
        } else if (digit == 10) {
            str_hex += "A";
        } else if (digit == 11) {
            str_hex += "B";
        } else if (digit == 12) {
            str_hex += "C";
        } else if (digit == 13) {
            str_hex += "D";
        } else if (digit == 14) {
            str_hex += "E";
        } else if (digit == 15) {
            str_hex += "F";
        }
    }
    return str_hex;
}