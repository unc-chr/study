/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB36.cpp
*   Author：leekaihua
*   Date：2023年04月29日
*   Brife：
*



*/

#include <iostream>
#include <vector>
#include "ads.h"
using namespace std;

int calcu(vector<int>& num) {
    int result = -101;
    int sum_curr = 0;
    for (int i = 0; i < num.size(); i++) {
        if (sum_curr > 0) {
            sum_curr += num[i];
            cout << "sum_curr1: " << sum_curr << endl;
        } else {
            sum_curr = num[i];
            cout << "sum_curr2: " << sum_curr << endl;
        }
        if (result < sum_curr) {
            result = sum_curr;
            cout << "result: " << result << endl;
        }
    }

    return result;
}

int main() {
    int count;
    int input;
    cin >> count;
    cout << "count: " << count << endl;
    vector<int> num;
    for (int i = 0; i < count; i++) {
        cin >> input;
        num.push_back(input);
    }

    int result = calcu(num);
    cout << result << endl;

    return 0;
}