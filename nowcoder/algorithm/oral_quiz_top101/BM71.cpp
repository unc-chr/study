/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM71.cpp
*   Author：leekaihua
*   Date：2023年04月18日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定数组的最长严格上升子序列的长度。
     * @param arr int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int>& arr) {
        // write code here
        int length = arr.size();
        if (length < 2) {
            return length;
        }

        int result = 1;
        vector<int> dp(length, 1);
        for (int i = 1; i < length; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};

int main() {
    vector<int> arr {1,2,3,4,3,5};
    Solution instance;
    int result = instance.LIS(arr);
    cout << result << endl;

    return 0;
}