/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM26.cpp
*   Author：leekaihua
*   Date：2023年04月13日
*   Brife：
*



*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    public:
        vector<int> level_order(TreeNode* root) {
            vector<int> vector_treenode;
            if (root == nullptr) {
                return vector_treenode;
            }

            queue<TreeNode*> q_treenode;            
            q_treenode.push(root);
            while (!q_treenode.empty()) {
                root = q_treenode.front();
                q_treenode.pop();
                vector_treenode.push_back(root->val);
                if (root->left) {
                    q_treenode.push(root->left);
                }
                if (root->right) {
                    q_treenode.push(root->right);
                }
            }

            return vector_treenode;
        }
};

int main() {
    TreeNode* t1 = new TreeNode(3);
    TreeNode* t2 = new TreeNode(9);
    TreeNode* t3 = new TreeNode(20);
    TreeNode* t4 = new TreeNode(15);
    TreeNode* t5 = new TreeNode(7);
    t1->left = t2; t1->right = t3;
    t2->left = nullptr; t2->right = nullptr;
    t3->left = t4; t3->right = t5;
    t4->left = nullptr; t4->right = nullptr;
    t5->left = nullptr; t5->right = nullptr;

    Solution instance;
    vector<int> result = instance.level_order(t1);
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}