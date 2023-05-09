/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB19.cpp
*   Author：leekaihua
*   Date：2023年05月06日
*   Brife：
*



*/

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#include "ads.h"

using namespace std;

bool find_path(vector<vector<int>>& matrix, int& num_vertexs, int& res) {
    queue<int> q;
    vector<int> visit(num_vertexs + 1, 0);
    visit[0] = 1;
    visit[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int q_size = q.size();
        res++;
        while (q_size--) {
            int curr = q.front();
            q.pop();
            if (curr == num_vertexs) {
                return true;
            }
            for (int i = 0; i < matrix[curr].size(); i++) {
                if (!visit[matrix[curr][i]]) {
                    q.push(matrix[curr][i]);
                    visit[matrix[curr][i]] = 1;
                }
            }
        }
        traverse_vector(visit);
        cout << "q: ";
        traverse_queue(q);
    }

    return false;
}

int main() {
    ifstream in_file;
    in_file.open("test_input_for_AB19.2");
    int num_vertexs;
    int num_edges;
    in_file >> num_vertexs >> num_edges;
    vector<vector<int>> matrix(num_vertexs + 1);
    int start, end;
    for (int i = 0; i < num_edges; i++) {
        in_file >> start >> end;
        matrix[start].push_back(end);
        matrix[end].push_back(start);
    }
    in_file.close();
    cout << "matrix: " << endl;
    for (int i = 0; i < matrix.size(); i++) {
        cout << "i: " << i << " --> ";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int res = 0;
    bool result = find_path(matrix, num_vertexs, res);
    res = result ? res - 1 : -1;
    cout << res << endl;

    return 0;
}