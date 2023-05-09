/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM79.cpp
*   Author：leekaihua
*   Date：2023年04月18日
*   Brife：
*



*/

#include <cmath>
#include <iostream>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
    public:
        void reverse(vector<int>& vec_int, int left, int right) {
            for (int i = left; i < (right + left) / 2; i++) {
                int temp = vec_int[i];
                vec_int[i] = vec_int[right + left- 1 - i];
                vec_int[right + left - 1 - i] = temp;
                }
            }

        void rotate(int m, vector<int>& a) {
            // write code here
            int n = a.size();
            m %= n;
            reverse(a, 0, n);
            reverse(a, 0, m);
            reverse(a, m, n);
        }

        int rob(vector<int>& nums, vector<int>& dp) {
            int length = nums.size();
            if (length == 1) {
                return nums[0];
            }
            if (length == 2) {
                return max(nums[0], nums[1]);
            }

            vector<bool> flag_rob(length, false);
            dp[0] = nums[0];
            dp[1] = nums[1];
            flag_rob[0] = true;
            flag_rob[1] = false;

            for (int i = 2; i < length; i++) {
                if (dp[i - 1] > dp[i - 2] + nums[i]) {
                    dp[i] = dp[i - 1];
                    flag_rob[i] = flag_rob[i - 1];
                } else {
                    dp[i] = dp[i - 2] + nums[i];
                    flag_rob[i] = flag_rob[i - 2];
                }
            }
            if (flag_rob[length - 1]) {
                return dp[length - 2];
            } else {
                return dp[length - 1];
            }

        }


        int rob1(vector<int>& nums) {
            //dp[i]表示长度为i的数组，最多能偷取多少钱
            vector<int> dp(nums.size() + 1, 0); 
            //选择偷了第一家
            dp[1] = nums[0]; 
            //最后一家不能偷
            for(int i = 2; i < nums.size(); i++) 
                //对于每家可以选择偷或者不偷
                dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]); 
            int res = dp[nums.size() - 1]; 
            cout << "rob1: ";
            for (auto iter = dp.begin(); iter != dp.end(); iter++) {
                std::cout << *iter << " ";
            }
            cout << endl;
            // traverse_vector(dp);
            //清除dp数组，第二次循环
            dp.clear(); 
            //不偷第一家
            dp[1] = 0; 
            //可以偷最后一家
            cout << "dp: ";
            for(int i = 2; i <= nums.size(); i++)  {
                //对于每家可以选择偷或者不偷
                dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]); 
                cout << dp[i] << " ";
            }
            //选择最大值
            cout << endl;
            cout << "rob2: ";
            for (auto iter = dp.begin(); iter != dp.end(); iter++) {
                std::cout << *iter << " ";
            }
            cout << endl;
            // traverse_vector(dp);

            return max(res, dp[nums.size()]); 
        }

};

// int main() {
//     vector<int> nums {7,8,9,4,11,5,23,9,1,44,32,69,55};
//     int length_nums = nums.size();
//     vector<int> nums2(length_nums, 0);
//     Solution instance;
//     for (int i = 0; i < length_nums; i++) {
//         instance.rotate(1, nums);
//         cout << "list: ";
//         traverse_vector(nums);
//         int result = instance.rob(nums, nums2);
//         cout << "summ: ";
//         traverse_vector(nums2);
//         cout << "result: " << result << endl;
//         cout << endl;
//     }
// 
// 
//     return 0;
// }

int main() {
    vector<int> nums {7,8,9,4,11,5,23,9,1,44,32,69,55};
    int length_nums = nums.size();
    Solution instance;
    for (int i = 0; i < length_nums; i++) {
        instance.rotate(1, nums);
        cout << "list: ";
        traverse_vector(nums);
        int result = instance.rob1(nums);
        cout << "result: " << result << endl;
        cout << endl;
    }


    return 0;
}