/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：ads.h
*   Author：leekaihua
*   Date：2023年04月18日
*   Brife：
*



*/
#pragma once

#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }

    friend std::ostream& operator<<(std::ostream& cout, const TreeNode& t) {
        std::cout << t.val;
        return cout;
    }

    friend std::ostream& operator<<(std::ostream& cout, const TreeNode* t) {
        std::cout << t->val;
        return cout;
    }
};

void traverse_tree_levelorder(TreeNode* root) {
    if (root == nullptr) {
        std::cout << "empty tree!" << std::endl;
        return;
    }

    std::vector<std::vector<int>> result;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int q_size = q.size();
        std::vector<int> result_temp;
        while (q_size > 0) {
            root = q.front();
            q.pop();
            q_size--;
            result_temp.push_back(root->val);
            if (root->left) {
                q.push(root->left);
            }
            if (root->right) {
                q.push(root->right);
            }
        }
        result.push_back(result_temp);
    }

    std::cout << "[" << std::endl;
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        std::cout << "    [";
        for (auto iter1 = (*iter).begin(); iter1 != (*iter).end() - 1; iter1++) {
            std::cout << *iter1 << ", ";
        }
        std::cout << (*iter).back();
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }

    int show_val() {
        return val;
    }
};

void traverse_list(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void traverse_vector(std::vector<int>& vec) {
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

void traverse_vector_vector(std::vector<std::vector<int>>& vec) {
    std::cout << "[" << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << "    [";
        for (int j = 0; j < vec[i].size() - 1; j++) {
            std::cout << vec[i][j] << ", ";
        }
        std::cout << vec[i].back() << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void traverse_stack_top2bottom(std::stack<T> st) {
    while (!st.empty()) {
        T temp = st.top();
        st.pop();
        std::cout << temp << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void traverse_stack_bottom2top(std::stack<T> st) {
    std::stack<T> st_temp;
    while (!st.empty()) {
        T temp = st.top();
        st.pop();
        st_temp.push(temp);
    }
    while (!st_temp.empty()) {
        T temp = st_temp.top();
        st_temp.pop();
        std::cout << temp << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void traverse_queue(std::queue<T> q) {
    while (!q.empty()) {
        T temp = q.front();
        q.pop();
        std::cout << temp << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void traverse_deque(std::deque<T> q) {
    while (!q.empty()) {
        T temp = q.front();
        q.pop_front();
        std::cout << temp << " ";
    }
    std::cout << std::endl;
}