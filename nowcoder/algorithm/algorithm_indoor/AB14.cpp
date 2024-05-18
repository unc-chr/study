/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB14.cpp
*   Author：leekaihua
*   Date：2023年05月06日
*   Brife：
*



*/

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }
    // 寻找节点x的最终祖先
    // 使用这段代码的时候，耗时平均在50ms左右
    // int find_parent(vector<int>& parent, int x){ //向上找到最高的父亲
    //     if(parent[x] != x)
    //         parent[x] = find_parent(parent, parent[x]);
    //     return parent[x];
    // }
    // 使用这段代码的时候，耗时平均在180ms左右
    int find_parent(vector<int>& parent, int x) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
    int miniSpanningTree(int n, int m, vector<vector<int> >& cost) {
        // 按照代价升序排列，用于选择代价最小的边加入到生成树中
        sort(cost.begin(), cost.end(), cmp);
        // 并查集数组，效果相当于链表
        vector<int> parent(n + 1, 0);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        int sum_cost = 0;
        int sum_clock = 0;
        // 选边
        for (int i = 0; i < m; i++) {
            clock_t start = clock();
            int parent_x = find_parent(parent, cost[i][0]);
            int parent_y = find_parent(parent, cost[i][1]);
            clock_t end = clock();
            sum_clock += end - start;
            if (parent_x == parent_y) {
                continue;
            }
            parent[parent_x] = parent_y;
            sum_cost += cost[i][2];
        }
        cout << "clock: " << sum_clock << endl;
        return sum_cost;
    }
};

int main() {
    ifstream in_file;
    in_file.open("test_input_for_AB14");
    int n, m;
    in_file >> n >> m;
    vector<vector<int>> cost(m, vector<int>(3, 0));
    for (int i = 0; i < m; i++) {
        in_file >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    Solution instance;
    int result = instance.miniSpanningTree(n, m, cost);
    cout << result << endl;

    return 0;
}