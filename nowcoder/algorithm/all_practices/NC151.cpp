/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：NC151.cpp
*   Author：leekaihua
*   Date：2023年05月13日
*   Brife：
* 	• 短除法实现求两个数的最大公约数
* 	• 从2开始进行短除，直到商不能被2整除
*   • 然后从3开始进行短处尝试，无法整除时约数每次加2进行尝试，直到约数超过两个商中的最小值。
*
*/

#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        int res = 1;
        while (a % 2 == 0 && b % 2 == 0) {
            res *= 2;
            a /= 2;
            b /= 2;
        }
        for (int i = 3; i <= min(a, b); i += 2) {
            while (a % i == 0 && b % i == 0) {
                res *= i;
                a /= i;
                b /= i;
            }
        }
        return res;
    }
};

int main() {
    Solution instance;
    int res = instance.gcd(28, 56);
    cout << res << endl;

    return 0;
}