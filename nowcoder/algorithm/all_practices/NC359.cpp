/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：NC359.cpp
*   Author：leekaihua
*   Date：2023年12月07日
*   Brife：
*



*/

#include <algorithm>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param num1 string字符串 
     * @param num2 string字符串 
     * @return string字符串
     */
    void borrow_digit(string& num1, int i) {
        int j = i + 1;
        for (; j < num1.size(); j++) {
            if (num1[j] != '0') {
                break;
            }
        }
        num1[j] = num1[j] - 1;
        j--;
        for (; j > i; j--) {
            num1[j] += 9;
        }
    }

    string substring(string num1, string num2) {
        bool is_negative = false;
        int start = 0;
        if (num1.length() < num2.length() 
                || num1.length() == num2.length() && num1 < num2) {
            string temp = num2;
            num2 = num1;
            num1 = temp;
            is_negative = true;
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        cout << "num1: " << num1 << endl;
        cout << "num2: " << num2 << endl;
        string result(num1.size(), '_');
        for (int i = 0; i < num1.size(); i++) {
            if (i >= num2.size()) {
                result[i] = num1[i];
                if (result[i] != '0') {
                    start = i;
                }
                cout << "result: " << result << endl;
                continue;
            }
            if (num1[i] >= num2[i]) {
                result[i] = num1[i] - num2[i] + '0';
            } else {
                cout << "num1 before borrow: " << num1 << endl;
                borrow_digit(num1, i);
                cout << "num1 before borrow: " << num1 << endl;
                result[i] = num1[i] + 10 - num2[i] + '0';
                if (result[i] != '0') {
                    start = i;
                }
                cout << "digit: " << result[i] << endl;
            }
        }
        cout << "result out: " << result << endl;
        if (result.back() == '0') {
            result = result.substr(0, start + 1);
        }
        reverse(result.begin(), result.end());
        if (is_negative) {
            result = '-' + result;
        }
        return result;
    }
};

int main() {
    // string num1 = "100000000";
    // string num2 = "1";
    // string num1 = "100000000";
    // string num2 = "1000000000";
    string num1 = "10000000000000000000000000000";
    string num2 = "1";
    Solution instance;
    string result = instance.substring(num1, num2);
    cout << "result: " << result << endl;

    return 0;
}