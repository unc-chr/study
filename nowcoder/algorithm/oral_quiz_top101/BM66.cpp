/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM66.cpp
*   Author：leekaihua
*   Date：2023年04月20日
*   Brife：
*



*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int len1 = str1.length();
        int len2 = str2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i < len1 + 1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < len2 + 1; i++) {
            dp[0][i] = 0;
        }
        int result = 0;
        int x = 0;
        int y = 0;
        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                cout << "i: " << i << ", j: " << j << ", ";
                cout << str1[i - 1] << ", " <<  str2[j - 1];
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                cout << ", " <<  dp[i][j] << endl;;
                if (result < dp[i][j]) {
                    result = dp[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        return str1.substr(x - result, result);
    }
};

int main() {
    string str1 = "1AB2345CD";
    string str2 = "12345EF";
    Solution instance;
    string result = instance.LCS(str1, str2);
    cout << result << endl;

    return 0;
}