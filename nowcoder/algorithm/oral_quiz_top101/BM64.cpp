/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM64.cpp
*   Author：leekaihua
*   Date：2023年04月13日
*   Brife：
*



*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param cost int整型vector 
     * @return int整型
     */
    int minCostClimbingStairs(vector<int>& cost) {
        // write code here
        int length = cost.size();
        if (length == 1 || length == 2) {
            return 0;
        }

        vector<int> sum_cost;
        sum_cost.push_back(0);
        sum_cost.push_back(0);
        int pre1 = 0;
        int pre2 = 0;
        for (int i = 2; i <= length; i++) {
            cout << "i: " << i << " ";
            pre1 = sum_cost[i - 1] + cost[i - 1];
            pre2 = sum_cost[i - 2] + cost[i - 2];
            sum_cost.push_back(min(pre1, pre2));
        }

        for (auto iter = sum_cost.begin(); iter != sum_cost.end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;
        return sum_cost.back();
    }
};

int main() {
    std::vector<int> cost {2,5,20};
    Solution instance;
    int result = instance.minCostClimbingStairs(cost);
    cout << "result: " << result << endl;

    return 0;
}