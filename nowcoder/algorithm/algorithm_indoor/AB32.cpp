/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB32.cpp
*   Author：leekaihua
*   Date：2023年05月04日
*   Brife：
*



*/
#include <climits>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "ads.h"

using namespace std;

struct HuffmanTreeNode {
    int weight;
    string code;
    bool is_leaf;
    HuffmanTreeNode* parent;
    HuffmanTreeNode* left_child;
    HuffmanTreeNode* right_child;
    HuffmanTreeNode* pre;
    HuffmanTreeNode* next;

    HuffmanTreeNode (int weight) {
        this->weight = weight;
        this->code = "";
        this->is_leaf = false;
        this->parent = nullptr;
        this->left_child = nullptr;
        this->right_child = nullptr;
        this->next = nullptr;
        this->pre = nullptr;
    }
};

// 从链表中选择权重最小的两个，用于构建哈夫曼树
// min2 表示最小权重，min1 表示次小权重
vector<HuffmanTreeNode*> select_min2(vector<HuffmanTreeNode*>& list_begin_end) {
    vector<HuffmanTreeNode*> min_2_node;
    HuffmanTreeNode* min1 = list_begin_end[0];
    HuffmanTreeNode* min2 = list_begin_end[1];
    HuffmanTreeNode* curr = min1->next;
    while (curr != list_begin_end[1]) {
        if (curr->weight <= min2->weight) {
            min1 = min2;
            min2 = curr;
        } else if (curr->weight > min2->weight && curr->weight <= min1->weight) {
            min1 = curr;
        }
        curr = curr->next;
    }
    min_2_node.push_back(min1);
    min_2_node.push_back(min2);

    return min_2_node;
}

// 构造所有字符的链表，方便之后筛选最小、次小权值的节点
// 题目限制出现次数最大为10^9，所以哨兵预设为INT_MAX
vector<HuffmanTreeNode*> build_list(vector<int>& freq) {
    HuffmanTreeNode* begin = new HuffmanTreeNode(INT_MAX);
    HuffmanTreeNode* end = new HuffmanTreeNode(INT_MAX);
    begin->next = end;
    end->pre = begin;
    HuffmanTreeNode* curr = begin;
    for (int i = 0; i < freq.size(); i++) {
        HuffmanTreeNode* temp = new HuffmanTreeNode(freq[i]);
        temp->is_leaf = true;
        temp->next = end;
        temp->pre = curr;
        curr->next = temp;
        end->pre = temp;
        curr = temp;
    }

    vector<HuffmanTreeNode*> result;
    result.push_back(begin);
    result.push_back(end);
    return result;
}

// 构建哈夫曼树
HuffmanTreeNode* build_huffman_tree(vector<HuffmanTreeNode*>& list_begin_end) {
    HuffmanTreeNode* begin = list_begin_end[0];
    HuffmanTreeNode* end = list_begin_end[1];
    // 终止条件，链表中只有一个节点，这个节点必定是哈夫曼树的根节点
    while (begin->next->next != end) {
        vector<HuffmanTreeNode*> min2 = select_min2(list_begin_end);
        // 使用最小、次小节点，构建哈夫曼树
        HuffmanTreeNode* left = min2[0];
        HuffmanTreeNode* right = min2[1];
        HuffmanTreeNode* temp_root = new HuffmanTreeNode(left->weight + right->weight);
        temp_root->left_child = left;
        temp_root->right_child = right;
        left->parent = temp_root;
        right->parent = temp_root;
        // 从链表中删除最小、次小节点
        left->pre->next = left->next;
        left->next->pre = left->pre;
        right->pre->next = right->next;
        right->next->pre = right->pre;
        // 链表中加入新的父亲节点。
        list_begin_end[1]->pre->next = temp_root;
        temp_root->pre = list_begin_end[1]->pre;
        temp_root->next = list_begin_end[1];
        list_begin_end[1]->pre = temp_root;
    }

    return begin->next;
}

// 计算最小带权路径
int calcu_wpl(HuffmanTreeNode* root) {
    stack<HuffmanTreeNode*> s;
    int sum_length = 0;

    HuffmanTreeNode* temp = nullptr;
    while (!s.empty() || root) {
        while (root) {
            s.push(root);
            if (root->parent) {
                if (root == root->parent->left_child) {
                    root->code = root->parent->code + "0";
                } else {
                    root->code = root->parent->code + "1";
                }
            }
            root = root->left_child;
        }
        temp = s.top();
        s.pop();
        if (temp->is_leaf) {
            sum_length += temp->weight * temp->code.length();
        }
        root = temp->right_child;
        cout << "temp_weight: " << temp->weight
             << ", temp->code: " << temp->code
             << ", temp->depth: " << s.size() << endl;
    }

    return sum_length;
}

int huffman(vector<int>& freq) {
    vector<HuffmanTreeNode*> list_begin_end = build_list(freq);
    HuffmanTreeNode* temp = list_begin_end[0];
    while (temp != nullptr) {
        cout << temp->weight << " ";
        temp = temp->next;
    }
    cout << endl;

    HuffmanTreeNode* root = build_huffman_tree(list_begin_end);
    int res = calcu_wpl(root);

    return res;
}

int main() {
    int num_char;
    cin >> num_char;
    vector<int> freq(num_char, 0);
    for (int i = 0; i < num_char; i++) {
        cin >> freq[i];
    }
    cout << "input: ";
    traverse_vector(freq);
    int result = huffman(freq);
    cout << result << endl;

    return 0;
}