/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM36.cpp
*   Author：leekaihua
*   Date：2023年04月13日
*   Brife：
*



*/

#include <iostream>

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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return true;
        }
        int left_depth = depth(pRoot->left);
        int right_depth = depth(pRoot->right);
        int diff = right_depth - left_depth;
        if (diff <= 1 && diff >= -1) {
            return true;
        }
        return false;
    }

    int depth(TreeNode* proot) {
        if (proot == nullptr) {
            return 0;
        }
        return max(depth(proot->left), depth(proot->right)) + 1;
    }
};

int main() {
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t7 = new TreeNode(7);
    
}