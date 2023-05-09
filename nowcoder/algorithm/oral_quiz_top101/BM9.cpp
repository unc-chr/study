/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM9.cpp
*   Author：leekaihua
*   Date：2023年04月12日
*   Brife：
*



*/

/**
 */
#include <iostream>
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
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* begin = new ListNode(-1);
        begin->next = head;
        ListNode* pre = begin;
        for (int i = 0; i < n; i++) {
            if (fast) {
                fast = fast->next;
            } else {
                return head;
            }
        }

        while (fast) {
            std::cout << "pre: " << pre->val;
            std::cout << " slow: " << slow->val;
            std::cout << " fast: " << fast->val << std::endl;
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;
        delete slow;

        return begin->next;
    }
};

int main() {
    using namespace std;
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    p1->next = p2;
    p2->next = nullptr;
    p3->next = nullptr;
    p4->next = p5;
    p5->next = nullptr;

    Solution instance;
    ListNode* new_head = instance.removeNthFromEnd(p1, 2);
    travel(new_head);
}