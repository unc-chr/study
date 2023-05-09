/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM3.cpp
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
    }
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    void reverse (ListNode* head, ListNode* tail) {
        ListNode* curr_tail = nullptr;
        ListNode* new_tail = head;
        while (head != tail) {
            ListNode* temp = head->next;
            head->next = curr_tail;
            curr_tail = head;
            head = temp;
        }
        tail = new_tail;
        head = curr_tail;
    }

    ListNode* find_reverse_range(ListNode* curr, int k) {
        ListNode* curr_bak = curr;
        for (int i = 0; i < k; i++) {
            if (curr) {
                curr = curr->next;
            } else {
                return curr_bak;
            }
        }

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* new_head = nullptr;
        fast = find_reverse_range(fast, k);
        std::cout << "slow: " << slow->val << std::endl;
        std::cout << "fast: " << fast->val << std::endl;
        if (fast == head) {
            return head;
        }
        reverse(slow, fast);
        new_head = slow;
        ListNode* begin = fast;

        while (find_reverse_range(fast, k) != fast) {
            reverse(slow, fast);
            begin->next = slow;
            begin = fast;
        }

        return head;
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
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = nullptr;

    Solution instance;
    ListNode* new_head = instance.reverseKGroup(p1, 2);
    // travel(new_head);
}