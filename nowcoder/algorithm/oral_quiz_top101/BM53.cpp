/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM53.cpp
*   Author：leekaihua
*   Date：2023年04月15日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

void traverse(vector<int>& vec) {
    for(auto iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int minNumberDisappeared(vector<int>& nums) {
        // write code here
        int length = nums.size();
        if (length == 0) {
            return 1;
        }
        traverse(nums);

        for (int i = 0; i < length; i++) {
            if (nums[i] <= 0) {
                nums[i] = length + 1;
            }
        }
        traverse(nums);
        for (int i = 0; i < length; i++) {
            cout << "i: " << i << ", nums[i]: " << nums[i]
                << ", nums[nums[i] - 1]: " << nums[nums[i] - 1] << endl;
            if (nums[i] <= length) {
                nums[nums[i] - 1] *= -1;
            }
            cout << "i: " << i << ", nums[i]: " << nums[i]
                << ", nums[nums[i] - 1]: " << nums[nums[i] - 1] << endl;
        }
        traverse(nums);
        
        for (int i = 0; i < length; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        traverse(nums);
        return length + 1;
    }
};

int main() {
    vector<int> nums {3,2,1};
    Solution instance;
    int result =  instance.minNumberDisappeared(nums);
    cout << result << endl;

    return 0;
}