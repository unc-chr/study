/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：NC154.cpp
*   Author：leekaihua
*   Date：2023年05月13日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int foundOnceNumber(vector<int>& arr, int k) {
        int res = 0;
        if (k % 2 == 0) {
            for (int i = 0; i < arr.size(); i++) {
                res ^= arr[i];
            }
            return res;
        }
        vector<int> digits(32, 0);
        for (int i = 31; i >= 0; i--) {
            int sum = 0;
            for (int j = 0; j < arr.size(); j++) {
                sum += arr[j] & 1;
                cout << j << ": " << arr[j] << " ";
                arr[j] >>= 1;
                cout << arr[j] << endl;
            }
            cout << sum << endl;
            digits[i] = sum % k;
        }
        for (int i = 0; i < 32; i++) {
            res = res * 2 + digits[i];
        }
        return res;
    }
};

int main() {
    Solution instance;
    vector<int> arr {4,4,1,1,5};
    int k = 2;
    int res = instance.foundOnceNumber(arr, k);
    cout << res << endl;

    return 0; 
}