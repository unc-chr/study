/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM73.cpp
*   Author：leekaihua
*   Date：2023年04月20日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A string字符串 
     * @return int整型
     */
    int getLongestPalindrome(string A) {
        // write code here
        int length = A.length();
        if (length < 2) {
            return length;
        }

        // 将原先的字符串插入#字符，消除奇数个字符和偶数个字符造成的差异。
        string s = "#";
        for (int i = 0; i < length; i++) {
            s += A[i];
            s += '#';
        }
        // 回文子串的最右侧可以到达的最大值
        int right_index = 0;
        // 到达回文子串的最右侧时，回文子串的中间字符的位置 
        int mi_index = 0; 
        // 记录以每个字符为中心，回文子串的长度半径
        int result = 0;
        vector<int> r(s.length(), 1);
        for (int i = 0; i < s.length(); i++) {
            cout << "i: " << i << endl;
            cout << "right_index: " << right_index << endl;
            cout << "mi_index: " << mi_index << endl;
            if (i < right_index) {
                if (i < right_index - r[2 * mi_index - i]) {
                    r[i] = r[2 * mi_index - i];
                    cout << "  1: " << r[i] << endl;
                    result = max(result, r[i]);
                    continue;
                }
                if (i > right_index - r[2 * mi_index - i]) {
                    r[i] = right_index - i;
                    cout << "  2: " << r[i] << endl;
                    result = max(result, r[i]);
                    continue;
                }
            }
            while ((i + r[i] < s.length()) && (i - r[i] >= 0) && s[i + r[i]] == s[i - r[i]]) {
                cout << "  3: " << s[i + r[i]] << " " << s[i - r[i]] << endl;
                r[i]++;
                cout << "  3: " << r[i] << endl;
            }
            result = max(result, r[i]);
            if (i + r[i] > right_index) {
                right_index = i + r[i];
                mi_index = i;
            }
        }
        cout << A << endl;
        cout << s << endl;
        traverse_vector(r);

        return result - 1;
    }
};

int main() {
    Solution instance;
    string s = "baabccc";
    int result = instance.getLongestPalindrome(s);
    cout << result << endl;

    return 0;
}