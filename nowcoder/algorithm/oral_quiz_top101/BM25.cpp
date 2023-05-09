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
#include <stack>
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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    vector<int> postorderTraversal(TreeNode* root) {
        // write code here
        vector<int> vector_treenode;
        stack<TreeNode*> stack_treenode;
        TreeNode* pre = nullptr;

        while (root || !stack_treenode.empty()) {
            while (root) {
                stack_treenode.push(root);
                root = root->left;
            }

            // 为什么不能将node换成root呢？
            // 如果使用root，那么如果root无右孩子，或者右孩子已经被访问过
            // 当前循环结束时还会把root再次压栈，陷入死循环
            // 所以使用pop，将root弹出，下一个访问root的右孩子或者root的父亲
            TreeNode* node = stack_treenode.top();
            stack_treenode.pop();
            // 无右孩子，或者右子树已经访问过，可以处理当前根节点
            if (node->right == nullptr || node->right == pre) {
                vector_treenode.push_back(node->val);
                pre = node;
            } else {
            // 有右孩子，并且尚未访问，开始访问右子树
                stack_treenode.push(node);
                root = node->right;
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
    vector<int> result = instance.postorderTraversal(t1);
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}