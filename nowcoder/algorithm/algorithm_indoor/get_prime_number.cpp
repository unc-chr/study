/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：get_prime_number.cpp
*   Author：leekaihua
*   Date：2023年05月05日
*   Brife：
*



*/

#include <cmath>
#include <iostream>
#include <vector>
#include <map>

#include "ads.h"

using namespace std;

bool is_prime(int m) {
    if (m == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(m); i++) {
        if (m % i == 0) {
            return false;
        }
    }
    return true;
}

// 求数字num的所有素因子，不去中版本，结果中所有数字的乘积是num
vector<int> get_prime_factor_complete(int num) {
    vector<int> prime_factor;
    // 除去所有 2 的倍数的因子
    while (num % 2 == 0) {
        num /= 2;
        prime_factor.push_back(2);
    }

    // 此时 num 一定是奇数，且素因子不可能是偶数
    // 因此试探的步长设定为2
    for (int i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            num /= i;
            prime_factor.push_back(i);
        }
    }

    // 如果 num 是一个大于2的素数，那么无法被前两步骤分解
    if (num > 2) {
        prime_factor.push_back(num);
    }
    return prime_factor;
}

// 求数字num的所有素因子，去重版本，只保留素数
vector<int> get_prime_factor_unique(int num) {
    vector<int> prime_factor;
    bool flag = false;
    // 除去所有 2 的倍数的因子
    while (num % 2 == 0) {
        num /= 2;
        flag = true;
    }
    if (flag) {
        prime_factor.push_back(2);
    }

    // 此时 num 一定是奇数，且素因子不可能是偶数
    // 因此试探的步长设定为2
    for (int i = 3; i <= sqrt(num); i += 2) {
        flag = false;
        while (num % i == 0) {
            num /= i;
            flag = true;
        }
        if (flag) {
            prime_factor.push_back(i);
        }
    }

    // 如果 num 是一个大于2的素数，那么无法被前两步骤分解
    if (num > 2) {
        prime_factor.push_back(num);
    }
    return prime_factor;
}

int main() {
    int range = 100;
    vector<int> result;
    for (int i = 2; i < range + 1; i++) {
        result = get_prime_factor_unique(i);
        // result = get_prime_factor_complete(i);
        cout << i << ": ";
        traverse_vector(result);
    }

    return 0;
}