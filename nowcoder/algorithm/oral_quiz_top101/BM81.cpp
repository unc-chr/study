/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM81.cpp
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
     * 两次交易所能获得的最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        if (prices.size() == 1) {
            return 0;
        }

        int rise1 = 0;
        int rise2 = 0;
        int collect = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                collect += prices[i] - prices[i - 1];
            }
            if (prices[i] <= prices[i - 1] || i == prices.size() - 1) {
                if (rise2 <= collect) {
                    rise1 = rise2;
                    rise2 = collect;
                } else if (rise1 < collect) {
                    rise1 = collect;
                }
                collect = 0;
            }
            cout << "rise1: " << rise1 << " rise2: " << rise2 << endl;
        }

        return rise1 + rise2;
    }
};

int main() {
    vector<int> prices {8, 9, 3, 5, 1, 3};
    Solution instance;
    int collect = instance.maxProfit(prices);

    cout << collect << endl;

    return 0;
}