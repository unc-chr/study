/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM61.cpp
*   Author：leekaihua
*   Date：2023年04月26日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void path(
                vector<vector<int>>& matrix,
                vector<vector<int>>& walk,
                int x, int y,
                int& len_x, int& len_y,
                int& dis, int& result) {
            walk[x][y] = 1;
            dis++;
            if (result < dis) {
                result = dis;
            }
            if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y] && walk[x - 1][y] == 0) {
                path(matrix, walk, x - 1, y, len_x, len_y, dis, result);
            }
            if (x + 1 < len_x && matrix[x + 1][y] > matrix[x][y] && walk[x + 1][y] == 0) {
                path(matrix, walk, x + 1, y, len_x, len_y, dis, result);
            }
            if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y] && walk[x][y - 1] == 0) {
                path(matrix, walk, x, y - 1, len_x, len_y, dis, result);
            }
            if (y + 1 < len_y && matrix[x][y + 1] > matrix[x][y] && walk[x][y + 1] == 0) {
                path(matrix, walk, x, y + 1, len_x, len_y, dis, result);
            }
            walk[x][y] = 0;
            dis--;
        }

        int solve(vector<vector<int>>& matrix) {
            int len_x = matrix.size();
            int len_y = matrix[0].size();
            int dis = 0;
            int result = 0;
            vector<vector<int>> walk(len_x, vector<int>(len_y, 0));
            for (int x = 0; x < len_x; x++) {
                for (int y = 0; y < len_y; y++) {
                    path(matrix, walk, x, y, len_x, len_y, dis, result);
                }
            }

            return result;
        }
};

int main() {
    // vector<vector<int>> matrix {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };

    vector<vector<int>> matrix {
        {1,5,6},
        {2,4,9},
        {3,8,7}
    };

    Solution instance;
    int result = instance.solve(matrix);
    cout << result << endl;

    return 0;
}