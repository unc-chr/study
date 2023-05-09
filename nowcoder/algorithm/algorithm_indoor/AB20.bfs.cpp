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
#include <queue>

#include "ads.h"

using namespace std;

struct coor {
    int x;
    int y;
    coor(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

void bfs(vector<vector<int>>& map, 
            coor& from, coor& dest,
            int row, int col,
            int& res) {
    queue<coor> q_coor;
    q_coor.push(from);
    int path = 0;
    map[from.x][from.y] = 1;
    while (!q_coor.empty()) {
        int q_size = q_coor.size();
        path++;
        while (q_size--) {
            coor curr = q_coor.front();
            if (curr.x == dest.x && curr.y == dest.y) {
                res = path - 1;
                traverse_vector_vector(map);
                return;
            }
            q_coor.pop();
            if (curr.x - 1 >= 0 && map[curr.x - 1][curr.y] == 0) {
                q_coor.push(coor(curr.x - 1, curr.y));
                map[curr.x - 1][curr.y] = path;
            }
            if (curr.x + 1 < row && map[curr.x + 1][curr.y] == 0) {
                q_coor.push(coor(curr.x + 1, curr.y));
                map[curr.x + 1][curr.y] = path;
            }
            if (curr.y - 1 >= 0 && map[curr.x][curr.y - 1] == 0) {
                q_coor.push(coor(curr.x, curr.y - 1));
                map[curr.x][curr.y - 1] = path;
            }
            if (curr.y + 1 < col && map[curr.x][curr.y + 1] == 0) {
                q_coor.push(coor(curr.x, curr.y + 1));
                map[curr.x][curr.y + 1] = path;
            }
        }
    }
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

    coor from(x1 - 1, y1 - 1);
    coor dest(x2 - 1, y2 - 1);
    int res = -1;
    bfs(map, from, dest, row, col, res);
    cout << res << endl;

    return 0;
}