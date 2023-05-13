/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：NC106.cpp
*   Author：leekaihua
*   Date：2023年05月13日
*   Brife：
*



*/

#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 最大乘积
     * @param A int整型一维数组 
     * @param ALen int A数组长度
     * @return long长整型
     */
    long long solve(int* A, int ALen) {
        if (ALen == 3) {
            return (long long)(A[0] * A[1] * A[2]); 
        }
        if (ALen == 4) {
            long long res = A[0] * A[1] * A[2];
            res = max(res, (long long)(A[0] * A[1] * A[3]));
            res = max(res, (long long)(A[0] * A[1] * A[2]));
            res = max(res, (long long)(A[0] * A[2] * A[3]));
            res = max(res, (long long)(A[1] * A[2] * A[3]));
            return res;
        }
        int max1 = -10001;
        int max2 = -10002;
        int max3 = -10003;
        int min1 = 10001;
        int min2 = 10002;
        for (int i = 0; i < ALen; i++) {
            if (A[i] >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = A[i];
            } else if (A[i] >= max2) {
                max3 = max2;
                max2 = A[i];
            } else if (A[i] >= max3) {
                max3 = A[i];
            }
            if (A[i] <= min1) {
                min2 = min1;
                min1 = A[i];
            } else if (A[i] <= min2) {
                min2 = A[i];
            }
        }
        cout << min1 << " " << min2 << " " << max3 << " " << max2 << " " << max1 << endl;
        long long res = max1 * max2 * max3;
        res = max(res, (long long)(min1 * min2 * max3));
        return res;
    }
};

int main() {
    Solution instance;
    int A1[4] {3,4,1,2};
    int A2[] {3,4,1,2,6,7,23,5};
    int A3[] {-13,-14,1,2,-6,7,23,0};
    long long res = instance.solve(A1, 4);
    cout << res << endl;
    res = instance.solve(A2, 8);
    cout << res << endl;
    res = instance.solve(A3, 8);
    cout << res << endl;

    return 0;
}