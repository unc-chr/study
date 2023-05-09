/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM97.cpp
*   Author：leekaihua
*   Date：2023年04月14日
*   Brife：
*



*/
#include <iostream>
#include <vector>

using namespace std;

void traverse(vector<int>& a) {
    for (auto iter = a.begin(); iter != a.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

class Solution {
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    void reverse(vector<int>& vec_int, int left, int right) {
        for (int i = left; i < (right + left) / 2; i++) {
            int temp = vec_int[i];
            vec_int[i] = vec_int[right + left- 1 - i];
            vec_int[right + left - 1 - i] = temp;
        }
    }

    vector<int> solve(int n, int m, vector<int>& a) {
        // write code here
        reverse(a, 0, n);
        traverse(a);
        reverse(a, 0, m);
        traverse(a);
        reverse(a, m, n);
        traverse(a);
        
        return a;
    }
};

int main() {
    Solution instance;
    vector<int> a {1, 2, 3, 4, 5, 6};
    vector<int> result = instance.solve(6, 2, a);
    traverse(result);

    return 0;    
}