/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：NC319.cpp
*   Author：leekaihua
*   Date：2023年12月05日
*   Brife：
*



*/

#include <iostream>
#include <map>
#include <random>
#include <unordered_map>

using std::cout;
using std::endl;
using std::map;
using std::unordered_map;
using std::vector;

class Solution {
    public:
        // rand5，离散均匀分布
        int rand5() {
            std::random_device rd;  // 用于生成随机数种子
            std::mt19937 gen(rd()); // 生成随机数引擎
            std::uniform_int_distribution<> distribution(1, 5); // 定义范围为 1~5 的均匀分布
            return distribution(gen);    
        }

        // 核心算法是，使用 1~5 的离散均匀分布构成 1~25 的离散均匀分布
        // 然后只保留 1~21，此时每个数值等概率出现 ，均为 1/25。
        // 将 1~21 映射到 0~6，使用取余运算，0~6 等待率出现，为 3/25。
        // 最后生成的随机数+1，0~6 对应 1~7。
        int rand7() {
            int target = -1;
            while (!(1 <= target && target <= 21)) {
                target = 5 * (rand5() - 1) + rand5();
            }
            return target % 7 + 1;
        }

        // 测试
        // 统计 n 轮随机数生成，数据的期望、分布情况。// rand5，离散均匀分布
        void test_rand7(int test_round) {
            int sum_rand = 0;
            int temp = -1;
            map<int, int> rand_count;
            vector<int> result(test_round, -1);
            for (int i = 0; i < test_round; i++) {
                temp = rand7();
                result[i] = temp;
                sum_rand += temp;
                if (rand_count.find(temp) == rand_count.end()) {
                    rand_count[temp] = 1;
                } else {
                    rand_count[temp]++;
                }
            }
            cout << "test " << test_round << " rounds." << endl;
            cout << "rand average is: " << double(sum_rand)/test_round << endl;
            cout << "rand frequency:" << endl;
            for (auto iter = rand_count.begin(); iter != rand_count.end(); iter++) {
                cout << "rand: " << iter->first 
                        << ", count: " << iter->second
                        << ", freq: " << double(iter->second)/test_round << endl;
            }
        }
    };

int main() {
    Solution instance;
    instance.test_rand7(10000);

    return 0;
}