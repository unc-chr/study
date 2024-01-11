/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：NC149.cpp
*   Author：leekaihua
*   Date：2023年11月26日
*   Brife：
*   牛客网算法练习，KMP算法。
*   网址：https://www.nowcoder.com/practice/bb1615c381cc4237919d1aa448083bcc?tpId=196&tqId=37564
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::string;
using std::vector;

class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 计算模板串target在文本串pattern中出现了多少次
         * @param target string字符串 模板串
         * @param pattern string字符串 文本串
         * @return int整型
         */
        void get_next(string& pattern, vector<int>& next_pos) {
            next_pos[0] = 0;
            bool flag = true;
            for (int i = 1; i < pattern.length(); i++) {

                int result = 0;
                for (int j = 0; j < i; j++) {
                    
                    flag = true;
                    for (int k = 0; k <= j; k++) {
                        if (pattern[k] != pattern[i - j + k]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        result = max(result, j + 1);
                    }
                }
                next_pos[i] = result;
            }
        }

        int kmp(string target, string pattern) {
            vector<int> next_pos(pattern.length(), 0);
            get_next(pattern, next_pos);
            int i = 0; // i 是文本串的指针
            int j = 0; // j 是模式串的指针
            int start = 0;
            int count = 0;
            while (i < target.length()) {
                cout << "i=" << i << ", j=" << j << endl;
                // j 遍历完模式串，匹配命中一次
                // 计数变量 count 加1，指针 j 归零以备下次统计，指针 start 向后顺延一个字符
                if (j == pattern.length()) {
                    count++;
                    j = 0;
                    i = ++start;
                    cout << "here, got 1" << endl;
                }
                // 文本串和模式串字符相同，则继续比较下一个字符。
                if (target[i] == pattern[j]) {
                    i++;
                    j++;
                    continue;
                }
                // 文本串和模式串字符不同，按照 next 数组的情况进行模式串的回退
                if (j == 0) {
                    i++;
                } else {
                    j = next_pos[j - 1];
                }
                start = i - j;
            }
            if (i == target.length() && j == pattern.length()) {
                count++;
            }

            return count;
        }
};

int main() {
    string target = "abababab";
    string pattern = "ababab";
    Solution instance;
    int result = instance.kmp(target, pattern);
    cout << result << endl;
    return 0;
}