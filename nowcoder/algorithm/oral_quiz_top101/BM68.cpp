/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM68.cpp
*   Author：leekaihua
*   Date：2023年04月14日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

void traverse(vector<int>& vec) {
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> path(n, 0);
        traverse(path);
        path[0] = matrix[0][0];
        for (int i = 1; i < n; i++) {
            path[i] = path[i - 1] + matrix[0][i];
        }
        traverse(path);
        for (int i = 1; i < n; i++) {
            path[0] = matrix[i][0] + path[0];
            for (int j = 1; j < m; j++) {
                path[j] = min(path[j], path[j - 1]) + matrix[i][j];
            }
            traverse(path);
        }

        return path[n - 1];
    }
};

int main() {
    vector<vector<int>> matrix {
        {1, 3, 5, 9},
        {8, 1, 3, 4},
        {5, 0, 6, 1},
        {8, 8, 4, 0}
    };
    Solution instance;
    int result = instance.minPathSum(matrix);
    cout << result << endl;

    return 0;
}