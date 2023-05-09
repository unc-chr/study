/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM55.cpp
*   Author：leekaihua
*   Date：2023年04月20日
*   Brife：
*



*/

#include <iostream>
#include <vector>
#include <algorithm>

#include "ads.h"

using namespace std;

class Solution {
public:
    void permute_core(vector<int>& num, vector<vector<int>>& result, int lo) {
        for (int hi = lo; hi < num.size(); hi++) {
            swap(num[lo], num[hi]);
            if (lo == num.size() - 1) {
                result.push_back(num);
            } else {
                permute_core(num, result, lo + 1);
            }
            swap(num[hi], num[lo]);
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        int lo = 0;
        permute_core(num, result, lo);

        return result;
    }
};

int main() {
    vector<int> num {1,2,3,4};
    Solution instance;
    auto result = instance.permute(num);

    cout << endl;
    traverse_vector_vector(result);

    return 0;
}