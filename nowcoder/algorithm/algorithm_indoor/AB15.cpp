/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB15.cpp
*   Author：leekaihua
*   Date：2023年05月07日
*   Brife：
*



*/

#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "ads.h"

using namespace std;

class MyCmp {
    public:
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        }
};

int find_path(vector<vector<int>>& vertex_weight,
        int& target_vertex, int& num_vertexs) {
    // 访问标记数组
    vector<bool> visit(num_vertexs + 1, false);
    // 从节点0到节点n的最短距离数组
    vector<int> dist(num_vertexs + 1, INT_MAX);
    // 节点n的前一个节点数组
    vector<int> pre(num_vertexs + 1, 0);
    // 小顶堆，选择未被访问的，距离节点0最近的节点
    // 元素是vector<int>, {int, int},表示节点序号和距离
    dist[0] = 0;
    dist[1] = 0;
    priority_queue<vector<int>, vector<vector<int>>, MyCmp> pq;
    pq.push({1, 0});
    while (!pq.empty()) {
        priority_queue<vector<int>, vector<vector<int>>, MyCmp> pq_bak(pq);
        cout << "currnet queue: " << endl;
        while (!pq_bak.empty()) {
            vector<int> ssss = pq_bak.top();
            pq_bak.pop();
            cout << "node: " << ssss[0] << ", dist: " << ssss[1] << " " << endl;
        }
        cout << endl;
        vector<int> temp = pq.top();
        pq.pop();
        int curr = temp[0];
        int curr_path = temp[1];
        if (visit[curr]) {
            continue;
        } else {
            visit[curr] = true;
        }
        for (int next = 1; next < num_vertexs + 1; next++) {
            if (vertex_weight[curr][next] == 0) {
                continue;
            }
            int next_step = vertex_weight[curr][next];
            int next_path = dist[next];
            if (next_path > curr_path + next_step) {
                dist[next] = curr_path + next_step;
                pre[next] = curr;
                pq.push({next, dist[next]});
                cout << "curr: " << curr << ", next: " << next << ", dist[next]: " << dist[next] << endl;
            }
        }
    }

    stack<int> s;
    int curr_node = target_vertex;
    while (curr_node != 1) {
        s.push(curr_node);
        curr_node = pre[curr_node];
    }
    s.push(1);
    cout << "path: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    cout << "dist: ";
    traverse_vector(dist);
    cout << "pre: ";
    traverse_vector(pre);

    return dist[target_vertex] == INT_MAX ? -1 : dist[target_vertex];
}

int main() {
    ifstream in_file;
    in_file.open("test_input_for_AB15");
    int target_vertex;
    int num_edges;
    int num_vertexs;
    in_file >> target_vertex >> num_vertexs >> num_edges;
    // 使用邻接矩阵表示图
    vector<vector<int>> vertex_weight(num_vertexs + 1, vector<int>(num_vertexs + 1, 0));
    int start, end, weight;
    for (int i = 0; i < num_edges; i++) {
        in_file >> start >> end >> weight;
        vertex_weight[start][end] = weight;
        vertex_weight[end][start] = weight;
    }
    in_file.close();

    int res = find_path(vertex_weight, target_vertex, num_vertexs);
    cout << res << endl;

    return 0;
}