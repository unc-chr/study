/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：interview_8_queens.cpp
*   Author：leekaihua
*   Date：2024年03月17日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void traverse_chest_row_col_map(vector<int>& chest_row_col_map) {
        for (int i = 0; i < chest_row_col_map.size(); i++) {
            if (chest_row_col_map[i] != -1) {
                cout << "(" << i + 1 << "," << chest_row_col_map[i] + 1 << ")";
            }
        }
        cout << endl;
    }

    void print(vector<vector<string>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                cout << grid[i][j] << endl;
            }
            cout << endl;
        }
    }

    bool is_valid_pos(
            int row,
            int col, 
            vector<int>& chest_row_col_map) {
        // row + 1 行，col 列，是否和已经落子的皇后冲突
        // 判断条件是棋子在相同行、列、对角线
        for (int i = 0; i < row; i++) {
            if (col == chest_row_col_map[i] || 
                    abs(col - chest_row_col_map[i]) == abs(row - i)) {
                return false;
            }
        }
        return true;
    }
    void locate(
            int n, 
            int row,
            vector<int>& chest_row_col_map,
            vector<vector<int>>& chest_row_col_map_all) {
        if (row == n) {
            chest_row_col_map_all.push_back(chest_row_col_map);
            traverse_chest_row_col_map(chest_row_col_map);
            return;
        }
        // 放下第 row + 1 个棋子，即在第 row 行落子时
        // 测试落子的列数
        for (int col = 0; col < n; col++) {
            if (!is_valid_pos(row, col, chest_row_col_map)) {
                continue;
            }
            chest_row_col_map[row] = col;
            locate(n, row + 1, chest_row_col_map, chest_row_col_map_all);
            chest_row_col_map[row] = -1;
        }

    }

    void generate_desk(
                int n,
                vector<vector<int>>& chest_row_col_map_all,
                vector<vector<string>>& res) {
        for (int i = 0; i < chest_row_col_map_all.size(); i++) {
            vector<string> desk;
            for (int j = 0; j < chest_row_col_map_all[i].size(); j++) {
                string row(n, '.');
                row[chest_row_col_map_all[i][j]] = 'Q';
                desk.push_back(row);
            }
            res.push_back(desk);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        int row = 0;
        vector<vector<string>> res;
        vector<int> chest_row_col_map(n, -1);
        vector<vector<int>> chest_row_col_map_all;
        locate(n, row, chest_row_col_map, chest_row_col_map_all);

        generate_desk(n, chest_row_col_map_all, res);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    Solution instance;
    vector<vector<string>> res = instance.solveNQueens(n);
    instance.print(res);

    return 0;
}