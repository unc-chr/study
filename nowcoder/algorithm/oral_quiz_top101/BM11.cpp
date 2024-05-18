/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM11.cpp
*   Author：leekaihua
*   Date：2023年04月11日
*   Brife：
*



*/

/**
 * Definition for singly-linked list.
 */

#include <iostream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    private:
        int list2num(ListNode* head) {
            int num = 0;
            while (head) {
                num = num * 10 + head->val;
                head = head->next;
            }

            return num;
        }

        ListNode* num2list(int num) {
            ListNode* begin = new ListNode(0);
            ListNode* curr = begin;
            int digit = 0;
            while (num != 0) {
                digit = num % 10;
                num /= 10;
                ListNode* temp = new ListNode(digit);
                curr->next = temp;
                curr = curr->next;
            }
            curr->next = nullptr;

            return begin->next;
        }
    public:
        /**
        * 
        * @param head1 ListNode类 
        * @param head2 ListNode类 
        * @return ListNode类
        */
        ListNode* reverse(ListNode* head) {
            ListNode* new_head = nullptr;
            while (head) {
                ListNode* temp = head->next;
                head->next = new_head;
                new_head = head;
                head = temp;
            }

            return new_head;
        }

        ListNode* addInList(ListNode* head1, ListNode* head2) {
            // write code here
            int num1 = list2num(head1);
            int num2 = list2num(head2);
            int result = num1 + num2;
            ListNode* result_list_reverse = num2list(result);
            ListNode* result_list = reverse(result_list_reverse);

            return result_list;
        }
};

int main() {
    using namespace std;
    ListNode* p1 = new ListNode(9);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(7);
    p1->next = p2;
    p2->next = p3;
    p3->next = nullptr;

    ListNode* l1 = new ListNode(6);
    ListNode* l2 = new ListNode(3);
    l1->next = l2;
    l2->next = nullptr;

    Solution instance;
    ListNode* result = instance.addInList(p1, l1);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}