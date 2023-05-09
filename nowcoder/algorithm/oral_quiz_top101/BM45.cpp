/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM45.cpp
*   Author：leekaihua
*   Date：2023年04月23日
*   Brife：
*



*/

#include <iostream>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> result;
        int length = num.size();
        if (size == 0 || size > length) {
            return result;
        }
        
        deque<int> num_index;
        for (int i = 0; i < size; i++) {
            while (!num_index.empty() && num[i] >= num[num_index.back()]) {
                num_index.pop_back();
            }
            num_index.push_back(i);
        }
        result.push_back(num[num_index.front()]);

        for (int i = size; i < length; i++) {
            cout << endl;
            while (!num_index.empty() && num[i] >= num[num_index.back()]) {
                num_index.pop_back();
            }
            num_index.push_back(i);
            
            while (i - num_index.front() >= size) {
                num_index.pop_front();
            }
            result.push_back(num[num_index.front()]);
        }

        return result;
    }
};

int main() {
    vector<int> num {2,3,4,2,6,2,5,1};
    Solution instance;
    vector<int> result = instance.maxInWindows(num, 3);

    traverse_vector(result);

    return 0;
}