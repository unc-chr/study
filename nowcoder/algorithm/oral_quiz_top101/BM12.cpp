/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM12.cpp
*   Author：leekaihua
*   Date：2023年04月12日
*   Brife：
*



*/

#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int value) {
        val = value;
    }
};

void travel (ListNode* head) {
    std::cout << "travel: ";
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {
    public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
        ListNode* sortInList(ListNode* head) {
            // write code here
            std::vector<int> num;
            ListNode* p = head;
            while (p) {
                num.push_back(p->val);
                p = p->next;
            }
            sort(num.begin(), num.end());
            for (int i = 0; i < num.size(); i++) {
                std::cout << num[i] << " ";
            }
            std::cout << std::endl;
            p = head;
            for (auto iter = num.begin(); iter != num.end(); iter++) {
                p->val = *iter;
                p = p->next;
            }

            return head;
        }
};

int main() {
    using namespace std;
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(2);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = nullptr;

    Solution instance;
    ListNode* new_head = instance.sortInList(p1);
    travel(new_head);
}