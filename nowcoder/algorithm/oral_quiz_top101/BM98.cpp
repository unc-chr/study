/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM98.cpp
*   Author：leekaihua
*   Date：2023年04月14日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m && i < n; i++) {
            for (int j = i; j < n; j++) {
                result.push_back(matrix[i][j]);
                cout << matrix[i][j] << " ";
            }
            cout << endl;
            for (int j = i + 1; j < m; j++) {
                result.push_back(matrix[j][n - 1]);
                cout << matrix[j][n - 1] << " ";
            }
            n--;
            cout << endl;
            for (int j = n - 1; j >= i; j--) {
                result.push_back(matrix[m - 1][j]);
                cout << matrix[m - 1][j] << " ";
            }
            m--;
            cout << endl;
            for (int j = m - 1; j > i; j--) {
                result.push_back(matrix[j][i]);
                cout << matrix[j][i] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return result;
    }
};

int main() {
    vector<vector<int>> matrix {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution instance;
    vector<int> result = instance.spiralOrder(matrix);
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}