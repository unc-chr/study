/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB40.cpp
*   Author：leekaihua
*   Date：2023年05月02日
*   Brife：
*



*/

#include <iostream>
#include <vector>

#include "ads.h"

using namespace std;

// 计算背包至多能够装下多大价值的东西
int package_max_value(
        vector<int>& volumes,
        vector<int>& values,
        int volume_package,
        int num_object) {
    // 物品为0，或者背包空间为0的特殊情况，直接返回0
    cout << "here" << endl;
    if (num_object == 0 || volume_package == 0) {
        return 0;
    }
    vector<vector<int>> dp(num_object + 1, vector<int>(volume_package + 1, 0));
    for (int i = 1; i <= num_object; i++) {
        for (int j = 1; j <= volume_package; j++) {
            if (j < volumes[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - volumes[i - 1]] + values[i - 1]);
            }
        }
    }

    cout << "package max value:" << endl;
    traverse_vector_vector(dp);

    return dp[num_object][volume_package];
}

// 计算背包恰好装满时，能够装下的最大价值
int package_full_value(
        vector<int>& volumes,
        vector<int>& values,
        int volume_package,
        int num_object) {
    // 处理特殊情况
    if (volume_package == 0 || num_object == 0) {
        return 0;
    }

    vector<vector<int>> dp(num_object + 1,  vector<int>(volume_package + 1, 0));
    int temp;
    for (int i = 1; i <= num_object; i++) {
        for (int j = 1; j <= volume_package; j++) {
            if (j < volumes[i - 1]) {
                dp[i][j] = 0;
                continue;
            }
            temp = volumes[i - 1] == j ? values[i - 1] : 0;
            for (int k = 0; k < i; k++) {
                if (dp[k][j - volumes[i - 1]] != 0) {
                    temp = max(temp, dp[k][j - volumes[i - 1]] + values[i - 1]);
                }
            }
            dp[i][j] = temp;
        }
    }
    cout << "full package value:" << endl;
    traverse_vector_vector(dp);

    temp = 0;
    for (int i = 0; i <= num_object; i++) {
        temp = max(temp, dp[i][volume_package]);
    }

    return temp;
}

int main() {
    // int num_object;
    // int volume_package;
    // cin >> num_object;
    // cin >> volume_package;
    // vector<int> volumes(num_object, 0);
    // vector<int> values(num_object, 0);
    // for (int i = 0; i < num_object; i++) {
    //     cin >> volumes[i];
    //     cin >> values[i];
    // }
    int num_object = 3;
    int volume_package = 5;
    vector<int> volumes {2,4,1};
    vector<int> values {10, 5, 4};
    int max_value = package_max_value(volumes, values, volume_package, num_object);
    int full_value = package_full_value(volumes, values, volume_package, num_object);

    cout << max_value << endl;
    cout << full_value << endl;

    return 0;
}