/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM100.cpp
*   Author：leekaihua
*   Date：2023年04月27日
*   Brife：
*



*/

#include <iostream>
#include <map>
#include <vector>

#include "ads.h"

using namespace std;

struct ListNodeDu {
    int key;
    int val;
    ListNodeDu* pre;
    ListNodeDu* next;
    ListNodeDu(int key, int val) {
        this->key = key;
        this->val = val;
        pre = nullptr;
        next = nullptr;
    }
};

void traverse_listnodedu(ListNodeDu* head) {
    while (head) {
        std::cout << head->key << "->" << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void traverse_map(map<int, ListNodeDu*>& hash) {
    for (auto iter = hash.begin(); iter != hash.end(); iter++) {
        cout << iter->second->key << "->" << iter->second->val << " ";
    }
    cout << endl;
}


class Solution {
private:
    int capacity;
    int size;
    ListNodeDu* begin;
    ListNodeDu* end;
    map<int, ListNodeDu*> hash;
public:
    Solution(int capacity){
         // write code here
         this->capacity = capacity;
         this->size = 0;
         this->begin = new ListNodeDu(0, 0);
         this->end = new ListNodeDu(0, 0);
         this->begin->next = this->end;
         this->end->pre = this->begin;
    }

    void insert_as_1st(int key, ListNodeDu* temp) {
        size++;
        hash[key] = temp;
        temp->next = begin->next;
        temp->pre = begin;
        begin->next->pre = temp;
        begin->next = temp;
    }

    void delete_last() {
        ListNodeDu* temp = end->pre;
        end->pre = temp->pre;
        temp->pre->next = temp->next;
        hash.erase(temp->key);
        size--;
        delete temp;
    }

    void move_to_head(ListNodeDu* temp) {
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        temp->next = begin->next;
        temp->pre = begin;
        begin->next->pre = temp;
        begin->next = temp;
    }
    
    int get(int key) {
         // write code here
        if (hash.find(key) == hash.end()) {
            return -1;
        }
        ListNodeDu* temp = hash[key];
        move_to_head(temp);
        cout << "get key: " << key << endl;
        traverse_listnodedu(begin);
        traverse_map(hash);
        return temp->val;
    }
    
    void set(int key, int value){
         // write code here
         // 如果 key 已经存在
        if (hash.find(key) != hash.end()) {
            ListNodeDu* temp = hash[key];
            temp->val = value;
            move_to_head(temp);
            cout << "set key: " << key << ", value: " << value << endl;
            traverse_listnodedu(begin);
            traverse_map(hash);
            return;    
        }

        // 如果 key 不存在
        ListNodeDu* temp = new ListNodeDu(key, value);
        if (size == capacity) {    
            delete_last();
        }
        insert_as_1st(key, temp);
        cout << "set key: " << key << ", value: " << value << endl;
        traverse_listnodedu(begin);
        traverse_map(hash);
    }
};

int main() {
    vector<string> out;

    // vector<string> input_order {"set","set","get","set","get","set","get","get","get"};
    // vector<vector<int>> input_params {{1,1},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4}};
    // int capacity = 2;
    vector<string> input_order {"set","set","get","set","get","set","get","get","get"};
    vector<vector<int>> input_params {{1,0},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4}};
    int capacity = 2;

    Solution instance(capacity);
    for (int i = 0; i < input_order.size(); i++) {
        if (input_order[i] == "set") {
            instance.set(input_params[i][0], input_params[i][1]);
            out.push_back("null");
        } else {
            int res = instance.get(input_params[i][0]);
            out.push_back(to_string(res));
        }
    }

    for (int i = 0; i < input_order.size(); i++) {
        cout << input_order[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
    }
    cout << endl;

    return 0;
}