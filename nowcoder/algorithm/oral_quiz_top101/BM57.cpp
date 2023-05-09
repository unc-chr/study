/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM57.cpp
*   Author：leekaihua
*   Date：2023年04月25日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
    private:
        void pprint(vector<vector<char>>& grid) {
            for (int i = 0; i < grid.size(); i++) {
                cout << "line " << i << ": ";
                for (int j = 0; j < grid[0].size(); j++) {
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    void visit(vector<vector<char>>& grid, 
            int x, int y, int len_x, int len_y) {
        if (x < 0 || y < 0 || x >= len_x || y >= len_y) {
            return;
        }
        if (grid[x][y] == '0') {
            return;
        }
        grid[x][y] = '0';
        visit(grid, x -1 , y, len_x, len_y);
        visit(grid, x + 1, y, len_x, len_y);
        visit(grid, x, y - 1, len_x, len_y);
        visit(grid, x, y + 1, len_x, len_y);
    }

    int solve(vector<vector<char> >& grid) {
        // write code here
        int length_x = grid.size();
        if (length_x == 0) {
            return 0;
        }
        int length_y = grid[0].size();
        if (length_y == 0) {
            return 0;
        }
        int num_island = 0;
        for (int x = 0; x < length_x; x++) {
            for (int y = 0; y < length_y; y++) {
                if (grid[x][y] == '0') {
                    continue;
                }
                num_island++;
                visit(grid, x, y, length_x, length_y);
                pprint(grid);
            }
        }

        return num_island;
    }
};

int main() {
    vector<vector<char>> grid {
        {'1','1','0','0','0'},
        {'0','1','0','1','1'},
        {'0','0','0','1','1'},
        {'0','0','0','0','0'},
        {'0','0','1','1','1'}
    };
    Solution instance;
    int result = instance.solve(grid);

    cout << result << endl;

    return 0;
}