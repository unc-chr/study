/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM65.cpp
*   Author：leekaihua
*   Date：2023年04月20日
*   Brife：
*



*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 == 0 || len2 == 0) {
            return "-1";
        }

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                cout << "j: " << j << endl;
            }
            cout << "i: " << i << endl;
        }

        for (int k = 0; k < dp.size(); k++) {
            for (int l = 0; l < dp[0].size(); l++) {
                cout << dp[k][l] << " ";
            }
            cout << endl;
        }

        stack<char> s;
        int i = len1;
        int j = len2;
        while (dp[i][j] > 0) {
            if (dp[i][j] == dp[i][j - 1]) {
                j--;
            } else if (dp[i][j] == dp[i - 1][j]) {
                i--;
            } else {
                i--;
                j--;
                s.push(s1[i]);
            }
        }
        string result = "";
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }

        return result;
    }
};

int main() {
    Solution instance;
    string s2 = "nwlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarc";
    string s1 = "bynecdyggxxpklorellnmpapqfwkhopkmcoqhnwnkuewhsqmgb";
    string result = instance.LCS(s1, s2);
    cout << result << endl;

    return 0;
}
