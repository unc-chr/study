/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：NC32.cpp
*   Author：leekaihua
*   Date：2023年05月11日
*   Brife：
*



*/

#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int sqrt(int x) {
        // write code here
        if (x == 0) {
            return 0;
        }
        int lo = 1;
        int hi = x;
        while (true) {
            if (hi - lo <= 1) {
                break;
            }
            int mi = (lo + hi) / 2;
            if (mi <= x / mi) {
                lo = mi;
            } else {
                hi = mi;
            }           
        }

        return lo;
    }
};

int main() {
    int input;
    cin >> input;
    Solution instance;
    int res = instance.sqrt(input);
    cout << res << endl;

    return 0;
}