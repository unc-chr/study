/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM49.cpp
*   Author：leekaihua
*   Date：2023年04月23日
*   Brife：
*



*/

#include <cctype>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
    private:
        vector<vector<bool>> youxian {
            {true, true, false, false, true},
            {true, true, false, false, true},
            {true, true, true, false, true},
            {false, false, false, false, true},
            {true, true, true, true, true},
        };
        map<char, int> op2num {
            {'+', 0},
            {'-', 1},
            {'*', 2},
            {'(', 3},
            {')', 4}
        };

    public:
        int solve(string s) {
            int i = 0;
            int length = s.length();
            int num = 0;
            char op = '+';
            stack<int> nums;
            stack<char> ops;
            bool good_num = false;
            for (int i = 0; i < length; i++) {
                cout << endl;
                cout << "i: " << i << endl;
                cout << "s[i]: " << s[i] << endl;
                cout << "nums: ";
                traverse_stack_bottom2top(nums);
                cout << "symbol: ";
                traverse_stack_bottom2top(ops);
                // 遇到数字字符，构建数字
                if (isdigit(s[i])) {
                    num = num * 10 + s[i] - 48;
                    good_num = true;
                    if (i == length - 1) {
                        nums.push(num);
                    }
                    cout << "isdigit" << endl;
                    continue;
                }
                // 遇到符号字符时，数字结束，先将构建好的数字压栈
                if (good_num) {
                    nums.push(num);
                    good_num = false;
                    cout << "push: " << num << endl;
                    num = 0;
                }
                // 是符号字符，处理符号
                op= s[i];
                if (ops.empty()) {
                    ops.push(op);
                    continue;
                }
                char exp_op = ops.top();
                // 判断是否应该执行计算
                // 此时按照优先级判断，新运算符的优先级比栈顶符号的优先级高，不计算，继续压栈
                if (!youxian[op2num[exp_op]][op2num[op]]) {
                    ops.push(op);
                    continue;
                }
                // 新运算符的优先级比栈顶符号的优先级低，此时可以执行计算
                // 计算结果压栈操作数栈，运算符继续压栈符号栈
                if (op == '(') {
                    ops.push(op);
                    continue;
                }
                cout << "here" << endl;
                int exp_num2 = nums.top();
                nums.pop();
                int exp_num1 = nums.top();
                nums.pop();
                cout << exp_num1 << exp_op << exp_num2 << endl;
                if (exp_op == '+') {
                    nums.push(exp_num1 + exp_num2);
                } else if (exp_op == '-') {
                    nums.push(exp_num1 - exp_num2);
                } else if (exp_op == '*') {
                    nums.push(exp_num1 * exp_num2);
                }
                ops.pop();
                if (op == ')') {
                    ops.pop();
                }
                ops.push(op);
            }
            cout << endl;
            cout << "nums: ";
            traverse_stack_bottom2top(nums);
            cout << "symbol: ";
            traverse_stack_bottom2top(ops);
            while (!ops.empty()) {
                char exp_op = ops.top();
                ops.pop();
                int exp_num2 = nums.top();
                nums.pop();
                int exp_num1 = nums.top();
                nums.pop();
                cout << exp_num1 << exp_op << exp_num2 << endl;
                if (exp_op == '+') {
                    nums.push(exp_num1 + exp_num2);
                } else if (exp_op == '-') {
                    nums.push(exp_num1 - exp_num2);
                } else if (exp_op == '*') {
                    nums.push(exp_num1 * exp_num2);
                }
            }
            return nums.top();
        }
};


int main() {
    // string s = "3+2*3*4-1";
    // string s = "1+2";
    string s = "(2*(3-4))*5";
    Solution instance;
    int result = instance.solve(s);
    cout << result << endl;

    return 0;
}