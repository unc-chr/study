/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM76.cpp
*   Author：leekaihua
*   Date：2023年04月25日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool match(string str, string pattern) {
        int n1 = str.length();
        int n2 = pattern.length();
        //dp[i][j]表示str前i个字符和pattern前j个字符是否匹配
        vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false)); 
        //两个都为空串自然匹配
        dp[0][0] = true; 
        //初始化str为空的情况，字符串下标从1开始
        for(int i = 2; i <= n2; i++){ 
            //可以让自己前面个字符重复0次
            if(pattern[i - 1] == '*') 
                //与再前一个能够匹配空串有关
                dp[0][i] = dp[0][i - 2]; 
        }
        //遍历str每个长度
        for(int i = 1; i <= n1; i++){ 
            //遍历pattern每个长度
            for(int j = 1; j <= n2; j++){ 
                //当前字符不为*，用.去匹配或者字符直接相同
                if(pattern[j - 1] == '.' || pattern[j - 1] == str[i - 1]) { 
                      dp[i][j] = dp[i - 1][j - 1];
                //当前的字符为*
                } else { 
                    //若是前一位为.或者前一位可以与这个数字匹配
                    if(pattern[j - 2] == '.' || pattern[j - 2] == str[i - 1]) 
                        //转移情况
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];  
                    else
                        //不匹配
                        dp[i][j] = dp[i][j - 2]; 
                }
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    string str = "aaa";
    string pattern = "a*a";
    Solution instance;
    bool result = instance.match(str, pattern);
    if (result) {
        cout << "true" << endl;
    }  else {
        cout << "false" << endl;
    }

    return 0;
}