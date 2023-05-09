/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB18.cpp
*   Author：leekaihua
*   Date：2023年04月30日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <vector>

#include "ads.h"

using namespace std;

class heap_self {
    private:
        vector<int> room;
        // 下滤算法
        void move_down(int i) {
            int length = room.size();
            if (length < 2) {
                return;
            }
            while (i < length) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int maxpos = i;
                if (left < length && room[maxpos] < room[left]) {
                    maxpos = left;
                }
                if (right < length && room[maxpos] < room[right]) {
                    maxpos = right;
                }
                // 根节点是最大的，那么已经局部有序，可以终止
                if (maxpos == i) {
                    break;
                }
                // 孩子节点比父亲的值更大，将父亲节点和孩子节点中值较大的那个交换位置
                swap(room[maxpos], room[i]);
                i = maxpos;
            }
        }

        // 上滤算法
        void move_up(int i) {
            int length = room.size();
            if (length < 2) {
                return;
            }
            while (i >= 0) {
                int father = (i - 1) / 2;
                if (room[i] > room[father]) {
                    swap(room[i], room[father]);
                    i = father;
                } else {
                    break;
                }
            }
        }

    public:
        // 默认的构造函数
        heap_self() {}

        // 批量建堆的构造函数
        heap_self(const vector<int>& vec) {
            for (int i = 0; i < vec.size(); i++) {
                room.push_back(vec[i]);
            }
            for (int i = (room.size() - 2) / 2; i >= 0; i--) {
                move_down(i);
            }
        }

        // push 操作，将元素插入到向量的末尾，然后进行上滤
        void push(int x) {
            room.push_back(x);
            move_up(room.size() - 1);
        }

        int top() {
            if (room.size() == 0) {
                return -1;
            }
            return room[0];
        }

        int pop() {
            if (room.size() == 0) {
                return -1;
            }
            swap(room[0], room[room.size() - 1]);
            int res = room.back();
            room.pop_back();
            move_down(0);

            return res;
        }
};

int main() {
    int order_num;
    string input;
    cin >> input;
    order_num = stoi(input);
    
    int param = 0;
    int res = 0;
    heap_self instance;
    for (int i = 0; i < order_num; i++) {
        cin >> input;
        if (input == "push") {
            cin >> input;
            param = stoi(input);
            instance.push(param);
            continue;
        }
        if (input == "top") {
            res = instance.top();
        } else {
            res = instance.pop();
        }
        if (res == -1) {
            cout << "empty" << endl;
        } else {
            cout << "output: " << res << endl;
        }
    }

    return 0;
}