/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：interview.04.10.cpp
*   Author：leekaihua
*   Date：2024年04月01日
*   Brife：
*



*/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool compare(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        if (t1 == nullptr || t2 == nullptr) {
            return false;
        }
        if (t1->val != t2->val) {
            return false;
        }
        return compare(t1->left, t2->left) && compare(t1->right, t2->right);
    }

    bool traverse(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return false;
        }
        if (t1->val == t2->val) {
            std::cout << t1->val << ", " << t2->val << std::endl;
            return compare(t1, t2);
        }
        return traverse(t1->left, t2) || traverse(t1->right, t2);
    }

    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        if (t1 == nullptr || t2 ==  nullptr) {
            return false;
        }
        return checkSubTree(t1, t2);
    }
};

int main() {
    TreeNode* a1 = new TreeNode(1);
    TreeNode* a2 = new TreeNode(2);
    TreeNode* a3 = new TreeNode(3);
    a1->left = a2;
    a1->right = a3;
    TreeNode* b1 = new TreeNode(2);

    Solution ins;
    bool res = ins.checkSubTree(a1, b1);
    if (res) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}