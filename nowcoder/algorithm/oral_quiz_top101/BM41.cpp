/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM41.cpp
*   Author：leekaihua
*   Date：2023年04月18日
*   Brife：
*



*/
#include <iostream>
#include <queue>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    vector<int> traverse_inorder(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> stack_treenode;
        while (root || !stack_treenode.empty()) {
            while (root) {
                stack_treenode.push(root);
                root = root->left;
            }

            root = stack_treenode.top();
            stack_treenode.pop();
            result.push_back(root->val);
            root = root->right;
        }

        return result;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        int length_pre = pre.size();
        int length_vin = vin.size();
        if (length_pre == 0 || length_vin == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[0]);
        int root_index = 0;
        for (int i = 0; i < length_vin; i++) {
            if (vin[i] == pre[0]) {
                root_index = i;
                break;
            }
        }
        vector<int> pre_left(pre.begin() + 1, pre.begin() + 1 + root_index);
        vector<int> pre_right(pre.begin() + 1 + root_index, pre.end());
        vector<int> vin_left(vin.begin(), vin.begin() + root_index);
        vector<int> vin_right(vin.begin() + root_index + 1, vin.end());
        root->left = reConstructBinaryTree(pre_left, vin_left);
        root->right = reConstructBinaryTree(pre_right, vin_right);
        return root;
    }

    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // write code here
        vector<int> result;
        int length_pre = xianxu.size();
        int length_vin = zhongxu.size();
        if (length_pre == 0 || length_vin == 0) {
            return result;
        }

        TreeNode* head = reConstructBinaryTree(xianxu, zhongxu);
        vector<int> tra_vec = traverse_inorder(head);
        cout << "traverse tree: ";
        traverse_vector(tra_vec);
        cout << "head: " << head->val << endl;

        queue<TreeNode*> queue_treenode;
        queue_treenode.push(head);
        while (!queue_treenode.empty()) {
            traverse_queue(queue_treenode);
            int s_size = queue_treenode.size();
            TreeNode* temp = nullptr;
            while (s_size != 0) {
                temp = queue_treenode.front();
                queue_treenode.pop();
                if (temp->left) {
                    queue_treenode.push(temp->left);
                }
                if (temp->right) {
                    queue_treenode.push(temp->right);
                }
                s_size--;
            }
            result.push_back(temp->val);
        }

        return result;
    }
};

int main() {
    vector<int> xianxu {1,2,4,5,3};
    vector<int> zhongxu {4,2,5,1,3};
    Solution instance;
    vector<int> result = instance.solve(xianxu, zhongxu);    
    cout << "final result: ";
    traverse_vector(result);

    return 0;
}