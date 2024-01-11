/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：NC341.cpp
*   Author：leekaihua
*   Date：2023年12月05日
*   Brife：
*



*/

#include <iostream>
#include <unordered_map>

using namespace std;

const int mod_value = 1000000007;

class Solution {
    public:
        int getNums(int n) {
            long long op1 = (long long)n;
            long long op2 = (long long)(n + 1);
            long long op3 = (long long)(n + 2);

            if (op1 % 3 == 0) {
                op1 /= 3;
            } else if (op2 % 3 == 0) {
                op2 /= 3;
            } else if (op3 % 3 == 0) {
                op3 /= 3;
            }
        
            if (op1 % 2 == 0) {
                op1 /= 2;
            } else if (op2 % 2 == 0) {
                op2 /= 2;
            } else if (op3 % 2 == 0) {
                op3 /= 2;
            }

            long long temp1 = (op1 % mod_value * op2 % mod_value) % mod_value;
            long long temp2 = (temp1 * op3 % mod_value) % mod_value;
            return int(temp2);
        }

        void test_getNums(unordered_map<int, int>& test_case) {
            for (auto iter = test_case.begin(); iter != test_case.end(); iter++) {
                int temp = getNums(iter->first);
                if (temp != iter->second) {
                    cout << "input: " << iter->first << endl
                            << "expec: " << iter->second << endl
                            << "actua: " << temp << endl << endl;
                } else {
                    cout << endl;
                }
            }
        }
};

int main() {
    Solution instance;
    unordered_map<int, int> test_case;
    test_case[1] = 1;
    test_case[2] = 4;
    test_case[3] = 10;
    test_case[4] = 20;
    test_case[5] = 35;
    test_case[10] = 220;
    test_case[1000] = 167167000;
    test_case[123456789] = 87997853;
    test_case[999888877] = 873186385;
    test_case[1000000000] = 999999972;
    instance.test_getNums(test_case);
    return 0;    
}