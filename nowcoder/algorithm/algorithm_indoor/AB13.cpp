/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB13.cpp
*   Author：leekaihua
*   Date：2023年05月06日
*   Brife：
*



*/

#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

#include "ads.h"

using namespace std;

bool topo_sort(vector<vector<int>>& map, vector<int>& res) {
    // 计算邻接矩阵中，所有节点的入度
    for (int j = 1; j < map.size(); j++) {
        int sum = 0;
        for (int i = 1; i < map.size(); i++) {
            sum += map[i][j];
        }
        map[0][j] = sum;
    }
    // 遍历寻找拓扑排序序列
    queue<int> q;
    for (int i = 1; i < map.size(); i++) {
        if (map[0][i] == 0) {
            q.push(i);
        }
    }
    cout << "q: ";
    traverse_queue(q);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (int i = 1; i < map.size(); i++) {
            if (map[curr][i] == 1) {
                map[curr][i] = 0;
                map[0][i]--;
                if (map[0][i] == 0) {
                    cout << "push: " << i << endl;
                    q.push(i);
                }
            }
        }
        traverse_vector_vector(map);
    }
    
    traverse_vector(res);
    return res.size() == map.size() - 1 ? true : false;
}

int main() {
    int num_vertex;
    int num_edge;
    cin >> num_vertex >> num_edge;
    // 构造邻接矩阵
    vector<vector<int>> map(num_vertex + 1, vector<int>(num_vertex + 1, 0));
    int start, end;
    for (int i = 0; i < num_edge; i++) {
        cin >> start >> end;
        map[start][end] = 1;
    }
    // 找到指定邻接矩阵的拓扑排序序列
    vector<int> res;
    bool has_topo_seq = topo_sort(map, res);
    if (has_topo_seq) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
