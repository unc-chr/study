/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM94.cpp
*   Author：leekaihua
*   Date：2023年04月20日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        // write code here
        int length = arr.size();
        if (length < 3) {
            return 0;
        }

        int left = 0;
        int right = length - 1;
        int left_max = arr[left];
        int right_max = arr[right];
        long long result = 0;
        while (left < right) {
            left_max = max(left_max, arr[left]);
            right_max = max(right_max, arr[right]);
            if (left_max < right_max) {
                result += left_max - arr[left];
                left++;
            } else {
                result += right_max - arr[right];
                right--;
            }
            cout << "result: " << result << endl;
            cout << endl;
        }

        return result;
    }
};

int main() {
    vector<int> arr {3,1,2,5,2,4};
    Solution instance;
    long long result = instance.maxWater(arr);
    cout << result << endl;

    return 0;
}