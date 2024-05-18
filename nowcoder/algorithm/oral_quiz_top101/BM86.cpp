/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM86.cpp
*   Author：leekaihua
*   Date：2023年04月14日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        int length_s = s.length();
        int length_t = t.length();
        if (length_s == 0) {
            return t;
        }
        if (length_t == 0) {
            return s;
        }

        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int length_max = max(length_s, length_t);
        string result(length_max, '0');
        int digit = 0;
        int plus = 0;
        int digit_s = 0;
        int digit_t = 0;
        for (int i = 0; i < length_max; i++) {
            digit_s = i < length_s ? s[i] - 48 : 0;
            digit_t = i < length_t ? t[i] - 48 : 0;
            digit = digit_s + digit_t + plus;
            plus = digit / 10;
            digit %= 10;
            cout << "i: " << i
                    << ", digit_s: " << digit_s
                    << ", digit_t: " << digit_t 
                    << ", plus: " << plus
                    << ", digit: " << digit << endl;
            result[i] = digit + 48;
        }
        if (plus != 0) {
            result += plus + 48;
        }
        reverse(result.begin(), result.end());
        cout << endl;
        
        return result;
    }
};

int main() {
    // string s = "1";
    // string t = "99";
    string s = "9";
    string t = "99999999999999999999999999999999999999999999999999999999999994";
    Solution instance;
    string result = instance.solve(s, t);
    cout << result << endl;

    return 0;
}