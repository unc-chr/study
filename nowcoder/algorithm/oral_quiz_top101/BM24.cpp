/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM24.cpp
*   Author：leekaihua
*   Date：2023年04月12日
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
        vector<int> inorderTraversal(TreeNode* root) {
            // write code here
            vector<int> vector_treenode;
            cout << "1" << endl;
            if (root == nullptr) {
                return vector_treenode;
            }

            stack<TreeNode*> stack_treenode;
            TreeNode* temp = nullptr;

            while (root || !stack_treenode.empty()) {
                while (root) {
                    stack_treenode.push(root);
                    root = root->left;
                }
                
                temp = stack_treenode.top();
                cout << "temp: " << temp->val << endl;
                stack_treenode.pop();
                vector_treenode.push_back(temp->val);
                if (temp->right) {
                    root = temp->right;
                } else {
                    root = nullptr;
                }
            }
            return vector_treenode;
        }
};

int main() {
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    t1->left = t2; t1->right = nullptr;
    t2->left = nullptr; t2->right = t3;
    t3->left = nullptr; t3->right = nullptr;
    Solution instance;
    vector<int> result = instance.inorderTraversal(t1);
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}