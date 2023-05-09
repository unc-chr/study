/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：MGJ11.cpp
*   Author：leekaihua
*   Date：2023年04月11日
*   Brife：
*



*/

#include <iostream>
#include <sstream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
};

ListNode* list_merge(ListNode* list1, ListNode* list2);

int main() {
    int a, b;
    ListNode* list1_head = new ListNode();
    ListNode* curr = list1_head;
    string input;
    getline(cin, input);
    stringstream ss(input);
    while (ss >> a) {
        ListNode* temp = new ListNode();
        temp->value = a;
        curr->next = temp;
        curr = curr->next;
    }
    curr->next = nullptr;

    getline(cin, input);
    stringstream ss2(input);
    ListNode* list2_head = new ListNode();
    curr = list2_head;
    while (ss2 >> b) {
        ListNode* temp = new ListNode();
        temp->value = b;
        curr->next = temp;
        curr = curr->next;
    }
    curr->next = nullptr;

    ListNode* new_head = list_merge(list1_head->next, list2_head->next);
    while (new_head != nullptr) {
        cout << new_head->value << " ";
        new_head = new_head->next;
    }

    return 0;
}

ListNode* list_merge(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    ListNode* new_head = new ListNode();
    new_head->next = nullptr;
    ListNode* curr = new_head;
    while (list1 != nullptr || list2 != nullptr) {
        if (list1 == nullptr) {
            curr->next = list2;
            break;
        } else if (list2 == nullptr) {
            curr->next = list1;
            break;
        } else {
            if (list1->value <= list2->value) {
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
            }
        }
    }

    return new_head->next;
}