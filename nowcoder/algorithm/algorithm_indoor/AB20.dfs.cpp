/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB20.cpp
*   Author：leekaihua
*   Date：2023年05月05日
*   Brife：
*



*/

#include <fstream>
#include <iostream>
#include <vector>

#include "ads.h"

using namespace std;

void dfs(vector<vector<int>>& map, 
        int& res, int& sum,
        int x1, int y1,
        int& x2, int& y2,
        int& row, int& col) {
    if (x1 == x2 && y1 == y2) {
        map[x1][y1] = 1;
        traverse_vector_vector(map);
        cout << "res: " << sum << endl;
        res = min(res, sum);
        exit(EXIT_FAILURE);
        return;
    }
    sum++;
    map[x1][y1] = 1;

    if (y1 + 1 < col && map[x1][y1 + 1] == 0) {
        dfs(map, res, sum, x1, y1 + 1, x2, y2, row, col);
    }
    if (y1 - 1 >= 0 && map[x1][y1 - 1] == 0) {
        dfs(map, res, sum, x1, y1 - 1, x2, y2, row, col);
    }
    if (x1 + 1 < row && map[x1 + 1][y1] == 0) {
        dfs(map, res, sum, x1 + 1, y1, x2, y2, row, col);
    }
    if (x1 - 1 >= 0 && map[x1 - 1][y1] == 0) {
        dfs(map, res, sum, x1 - 1, y1, x2, y2, row, col);
    }
    sum--;
    map[x1][y1] = 0;
}

int main() {
    ifstream in_file;
    in_file.open("test_input_for_AB20");
    int row, col;
    in_file >> row >> col;
    vector<vector<int>> map(row, vector<int>(col, 0));
    int x1, y1, x2, y2;
    in_file >> x1 >> y1 >> x2 >> y2;
    char temp = '.';
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            in_file >> temp;
            if (temp == '.') {
                map[i][j] = 0;
            } else {
                map[i][j] = -1;
            }
        }
    }
    in_file.close();

    int res = 1000000;
    int sum = 0;
    x1--;
    y1--;
    x2--;
    y2--;
    dfs(map, res, sum, x1, y1, x2, y2, row, col);
    res = res == 1000000 ? -1 : res;
    cout << res << endl;
    return 0;
}