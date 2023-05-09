/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM38.cpp
*   Author：leekaihua
*   Date：2023年04月18日
*   Brife：
*



*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        bool meet1 = false;
        bool meet2 = false;
        TreeNode* pre = new TreeNode(-1);

        while (root || !s1.empty()) {
            while (root) {
                s1.push(root);
                root = root->left;
            }
            if (meet1 && meet2) {
                break;
            }

            TreeNode* node = s1.top();
            if (node->right == nullptr || node->right == pre) {
                pre = node;
                if (node->val == o1 || node->val == o2) {
                    if (!meet1) {
                        s2 = s1;
                        meet1 = true;
                    } else {
                        meet2 = true;
                        break;
                    }
                }
                s1.pop();
            } else {
                root = node->right;
            }
        }

        cout << "traverse stack1: ";
        traverse_stack_bottom2top(s1);
        cout << "traverse stack2: ";
        traverse_stack_bottom2top(s2);
        
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 < len2) {
            while (len2 != len1) {
                s2.pop();
                len2--;
            }
        } else {
            while (len1 != len2) {
                s1.pop();
                len1--;
            }
        }
        while (s1.size() != 0) {
            int t1 = s1.top()->val;
            int t2 = s2.top()->val;
            if (t1 == t2) {
                return t1;
            } else {
                s1.pop();
                s2.pop();
            }
        }

        return root->val;
    }
};

int main() {
    TreeNode* t1 = new TreeNode(3);
    TreeNode* t2 = new TreeNode(5);
    TreeNode* t3 = new TreeNode(1);
    TreeNode* t4 = new TreeNode(6);
    TreeNode* t5 = new TreeNode(2);
    TreeNode* t6 = new TreeNode(0);
    TreeNode* t7 = new TreeNode(8);
    TreeNode* t8 = new TreeNode(7);
    TreeNode* t9 = new TreeNode(4);
    t1->left = t2; t1->right = t3;
    t2->left = t4; t2->right = t5;
    t3->left = t6; t3->right = t7;
    t4->left = nullptr; t4->right = nullptr;
    t5->left = t8; t5->right = t9;
    t6->left = nullptr; t6->right = nullptr;
    t7->left = nullptr; t7->right = nullptr;
    t8->left = nullptr; t8->right = nullptr;
    t9->left = nullptr; t9->right = nullptr;
    Solution instance;
    // int result = instance.lowestCommonAncestor(t1, 5, 1);
    int result = instance.lowestCommonAncestor(t1, 3, 4);
    cout << result << endl;

    return 0;
}