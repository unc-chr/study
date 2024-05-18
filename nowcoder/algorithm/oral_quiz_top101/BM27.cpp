/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM27.cpp
*   Author：leekaihua
*   Date：2023年04月17日
*   Brife：
*



*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

void traverse(vector<int>& vec) {
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if (pRoot == nullptr) {
            return result;
        }

        stack<TreeNode*> stack_treenode0;
        stack<TreeNode*> stack_treenode1;
        stack_treenode0.push(pRoot);
        while (!stack_treenode0.empty() || !stack_treenode1.empty()) {
            // 遍历奇数层
            vector<int> temp_vec;
            while (!stack_treenode0.empty()) {
                TreeNode* temp = stack_treenode0.top();
                stack_treenode0.pop();
                temp_vec.push_back(temp->val);
                if (temp->left!= nullptr) {
                    stack_treenode1.push(temp->left);
                }
                if (temp->right!= nullptr) {
                    stack_treenode1.push(temp->right);
                }
            }
            if (!temp_vec.empty()) {
                result.push_back(temp_vec);
            }
            temp_vec.clear();

            // 遍历偶数层
            while (!stack_treenode1.empty()) {
                TreeNode* temp = stack_treenode1.top();
                stack_treenode1.pop();
                temp_vec.push_back(temp->val);
                if (temp->right!= nullptr) {
                    stack_treenode0.push(temp->right);
                }
                if (temp->left!= nullptr) {
                    stack_treenode0.push(temp->left);
                }
            }
            if (!temp_vec.empty()) {
                result.push_back(temp_vec);
            }
        }

        return result;
    }
    
};

int main() {
    TreeNode* t1 = new TreeNode(8);
    TreeNode* t2 = new TreeNode(6);
    TreeNode* t3 = new TreeNode(10);
    TreeNode* t4 = new TreeNode(5);
    TreeNode* t5 = new TreeNode(7);
    TreeNode* t6 = new TreeNode(9);
    TreeNode* t7 = new TreeNode(11);
    t1->left = t2; t1->right = t3;
    t2->left = t4; t2->right = t5;
    t3->left = t6; t3->right = t7;
    t4->left = nullptr; t4->right = nullptr;
    t5->left = nullptr; t5->right = nullptr;
    t6->left = nullptr; t6->right = nullptr;
    t7->left = nullptr; t7->right = nullptr;
    Solution instance;
    vector<vector<int>> result =  instance.Print(t1);
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        traverse(*iter);
    }
}