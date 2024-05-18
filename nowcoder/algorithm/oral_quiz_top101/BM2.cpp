/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM2.cpp
*   Author：leekaihua
*   Date：2023年04月07日
*   Brife：
*



*/

#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }

    int show_val() {
        return val;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         //加个表头
        ListNode* res = new ListNode(-1);
        res->next = head;
        std::cout << "head address: " << (void*)head << std::endl;
        std::cout << "res->next first address: " << (void*)(res->next) << std::endl;
        //前序节点
        ListNode* pre = res; 
        //当前节点
        ListNode* cur = head; 
        //找到m
        for(int i = 1; i < m; i++){ 
            pre = cur;
            std::cout << "now value: " << cur->show_val() << std::endl;
            cur = cur->next;
        }
        //从m反转到n
        for(int i = m; i < n; i++){ 
            std::cout << "curr: " << cur->show_val() << " ";
            std::cout << "res: " << res->show_val() << ", head_address: " << (void*)head << ", res->next_add:" << (void*)(res->next) << ", res->next: " << res->next->show_val() << " ";
            std::cout << "travel now: ";
            travel(head);
            std::cout << "res->next_address 1: " << (void*)res->next<< std::endl;
            ListNode* temp = cur->next;
            std::cout << "res->next_address 2: " << (void*)res->next<< std::endl;
            cur->next = temp->next;
            std::cout << "res->next_address 3: " << (void*)res->next<< std::endl;
            temp->next = pre->next;
            std::cout << "res->next_address 4: " << (void*)res->next<< std::endl;
            pre->next = temp;
            std::cout << "res->next_address 5: " << (void*)res->next<< std::endl;
        }
        //返回去掉表头
        return res->next; 
    }

    void travel(ListNode* head) {
        while(head) {
            std::cout << head->show_val() << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    using namespace std;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);
    ListNode n8(8);
    ListNode n9(9);
    ListNode n10(10);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n9;
    n9.next = &n10;
    n10.next = nullptr;

    Solution instance;
    ListNode* result = instance.reverseBetween(&n1, 4, 8);
    cout << "list head: ";
    result->show_val();
    cout << "list travel: " << endl;
    instance.travel(result);

    return 0;
}