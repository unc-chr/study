/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM87.cpp
*   Author：leekaihua
*   Date：2023年04月14日
*   Brife：
*



*/

#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n == 0) {
            return;
        }
        
        int j = -1;
        for (int i = 0; i < n; i++) {
            j++;
            while (A[j] < B[i]) {
                j++;
            }
            cout << "j: " << j << endl;
            for (int k = m + i - 1; k >= j; k--) {
                A[k + 1] = A[k];
            }
            A[j] = B[i];
        }
    }
};

int main() {
    int A[] {4, 5, 6, 0, 0, 0};
    int B[] {1, 2, 3};
    Solution instance;
    instance.merge(A, 6, B, 3);
    for (int i = 0; i < 6; i++) {
        cout << A[i] << " ";
    }

    return 0;
}