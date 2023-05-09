/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM39.cpp
*   Author：leekaihua
*   Date：2023年04月24日
*   Brife：
*



*/

#include <cctype>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>

#include "ads.h"

using namespace std;

class Solution {
    private:
        string int2str(int val) {
            string result = "";
            while (val != 0) {
                int rem = val % 10;
                val /= 10;
                result = char(rem + 48) + result;
            }

            return result;
        }

        vector<int> split(char* str) {
            vector<int> result;
            int num = 0;
            for (int i = 0; str[i] != '\0'; i++) {
                if (isdigit(str[i])) {
                    num = num * 10 + str[i] - 48;
                } else if (str[i] == '|') {
                    result.push_back(num);
                    num = 0;
                } else if (str[i] == '#') {
                    num = -1;
                }
            }

            return result;
        }

    public:
        char* Serialize(TreeNode* root) {
            if (root == nullptr) {
                return nullptr;
            }            

            queue<TreeNode*> q;
            q.push(root);
            string result = "";
            while (!q.empty()) {
                root = q.front();
                q.pop();
                if (root->val >= 0) {
                    string str = int2str(root->val);
                    result += str + '|';
                } else {
                    result += "#|";
                    continue;
                }
                if (root->left) {
                    q.push(root->left);
                } else {
                    TreeNode* temp = new TreeNode(-1);
                    q.push(temp);
                }
                if (root->right) {
                    q.push(root->right);
                } else {
                    TreeNode* temp = new TreeNode(-1);
                    q.push(temp);
                }
            }

            char* res = new char[result.length() + 1];
            strcpy(res, result.c_str());
            return res;
        }

        TreeNode* Deserialize(char* str) {
            if (str == nullptr) {
                return nullptr;
            }

            vector<int> result = split(str);

            queue<TreeNode*> q1;
            queue<TreeNode*> q2;
            TreeNode* real_root = new TreeNode(result[0]);
            q1.push(real_root);
            int i = 1;
            int size_q1 = 1;
            int size_q2 = 2;
            while (i < result.size()) {
                while (size_q2 > 0) {
                    q2.push(new TreeNode(result[i]));
                    i++;
                    size_q2--;
                }

                size_q1 = q1.size();
                while (size_q1 > 0) {
                    TreeNode* root = q1.front();
                    q1.pop();
                    size_q1--;
                    TreeNode* left_child = q2.front();
                    q2.pop();
                    TreeNode* right_child = q2.front();
                    q2.pop();
                    if (left_child->val != -1) {
                        root->left = left_child;
                        q1.push(left_child);
                    }
                    if (right_child->val != -1) {
                        root->right = right_child;
                        q1.push(right_child);
                    }
                }
                size_q1 = q1.size();
                size_q2 = 2 * size_q1;
            }

            return real_root;
        }
};

int main() {
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t7 = new TreeNode(7);
    TreeNode* t9 = new TreeNode(9);
    t1->left = t2; t1->right = t3;
    t2->left = nullptr; t2->right = nullptr;
    t3->left = t6; t3->right = t7;
    t6->left = nullptr; t6->right = nullptr;
    t7->left = nullptr; t7->right = t9;
    t9->left = nullptr; t9->right = nullptr;
    Solution instance;
    char* str = instance.Serialize(t1);
    cout << str << endl;

    TreeNode* root = instance.Deserialize(str);
    traverse_tree_levelorder(root);

    return 0;
}