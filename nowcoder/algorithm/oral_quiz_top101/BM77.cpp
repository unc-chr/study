/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM77.cpp
*   Author：leekaihua
*   Date：2023年04月24日
*   Brife：
*



*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    int longestValidParentheses(string s) {
        // write code here
        int length = s.length();
        if (length < 2) {
            return 0;
        }

        stack<char> kuohao;
        stack<int> len;
        vector<int> max_len(length, 0);
        int result = 0;
        for (int i = 0; i < length; i++) {
            // 左括号直接入栈，连续合法括号长度暂定为0
            if (s[i] == '(') {
                kuohao.push(s[i]);
                len.push(0);
                continue;
            }
            // 如果是右括号，但为空，也入栈，连续合法括号长度暂定为0
            if (kuohao.empty()) {
                kuohao.push(s[i]);
                len.push(0);
                continue;
            }
            char temp = kuohao.top();
            if (temp == '(') {
                kuohao.pop();

                int len_temp = len.top();
                len.pop();
                if (len_temp != 0) {
                    len.push(len_temp + 2);
                } else {
                    if (!len.empty()) {
                        len_temp = len.top();
                    } else {
                        len_temp = 0;
                    }
                    len.push(len_temp + 2);
                }
                max_len[i] = len_temp + 2;
                if (len_temp + 2 > result) {
                    result = len_temp + 2;
                }
            }
        }

        traverse_vector(max_len);
        return result;
    }
};

int main() {
    vector<string> test {
        "(()",
        ")()(()()((((((())(",
        "(())",
        "()",
        "()(())"
    };

    Solution instance;
    int result = 0;
    for (auto iter = test.begin(); iter != test.end(); iter++) {
        for (int i = 0; i < (*iter).length(); i++) {
            cout << (*iter)[i] << " ";
        }
        cout << endl;
        result = instance.longestValidParentheses(*iter);
        cout << result << endl;
        cout << endl;
    }

    return 0;
}