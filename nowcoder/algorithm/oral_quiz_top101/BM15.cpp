/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM15.cpp
*   Author：leekaihua
*   Date：2023年04月12日
*   Brife：
*



*/

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode* curr = head;
        ListNode* temp = nullptr;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
            
        }

        return head;
    }
};