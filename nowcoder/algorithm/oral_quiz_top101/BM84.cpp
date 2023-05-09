/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM83.cpp
*   Author：leekaihua
*   Date：2023年04月14日
*   Brife：
*



*/

#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;


class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        int length = strs.size();
        if (length == 0) {
            return "";
        }
        if (length == 1) {
            return strs[0];
        }
        int i = 0;
        for (; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                cout << "j: " << j << " i: " << i << " ch: " << ch << endl;
                if (i == strs[j].length() || strs[j][i] != ch) {
                    break;       
                }
            }
        }
        return strs[0].substr(0, i);
    }
};

int main() {
    Solution instance;
    vector<string> strs {"abca","abc","abca","abc","abcc"};
    string result = instance.longestCommonPrefix(strs);
    cout << result << endl;

    return 0;
}