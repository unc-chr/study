/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM101.cpp
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

struct ListNode_freq {
    int key;
    int value;
    int freq;
    ListNode_freq* next;
    ListNode_freq* pre;
    ListNode_freq(int key, int value) {
        this->key = key;
        this->value = value;
        freq = 1;
        pre = nullptr;
        next = nullptr;
    }
};

void traverse_map(map<int, vector<ListNode_freq*>>& freq_v) {
    for (auto iter = freq_v.begin(); iter != freq_v.end(); iter++) {
        cout << iter->first << ": ";
        ListNode_freq* temp = freq_v[iter->first][0]->next;
        while(temp && temp->next) {
            cout << temp->key << "->" << temp->value << "->freq:" << temp->freq << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
private:
    map<int, ListNode_freq*> kv;
    map<int, vector<ListNode_freq*> > freq_v;
    int least_freq;
    int size;
public:
    Solution() {
        least_freq = 1;
        size = 0;
    }

    void remove_freq(int freq) {
        delete freq_v[freq][0];
        delete freq_v[freq][1];
        freq_v.erase(freq);
    }

    void remove_last_node() {
        ListNode_freq* temp = freq_v[least_freq][1]->pre;
        temp->next->pre = temp->pre;
        temp->pre->next = temp->next;
        kv.erase(temp->key);
        // 这里的前提是，执行插入的时候容量已满.
        // 因此 least_freq 将被新插入的节点更新为1，这里就不用处理了。
        if (freq_v[least_freq][0]->next == freq_v[least_freq][1]) {
            remove_freq(least_freq);
        }
        size--;
        delete temp;
    } 

    void remove_from_freq(ListNode_freq* temp) {
        // 将节点从当前频率的链表中摘除
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        // 如果当前频率的节点不存在了，那么删除当前频率的映射。
        if (freq_v[temp->freq][0]->next == freq_v[temp->freq][1]) {
            remove_freq(temp->freq);
            // 如果删除的频率正好是最小频率，那么最小频率加1.
            if (temp->freq == least_freq) {
                least_freq++;
            }
        }
    }

    void insert_to_freq(ListNode_freq* temp) {
        // 如果当前频率哈希表中不存在 temp 的访问频率，需要新建
        // 新建的时候设定头尾哨兵节点
        if (freq_v.find(temp->freq) == freq_v.end()) {
            ListNode_freq* begin = new ListNode_freq(0, 0);
            ListNode_freq* end = new ListNode_freq(0, 0);
            begin->next = end;
            end->pre = begin;
            freq_v[temp->freq].push_back(begin);
            freq_v[temp->freq].push_back(end);
            // 新加的访问频率，需要判断是否是最小的访问频率
            if (temp->freq < least_freq) {
                least_freq = temp->freq;
            }
        }
        ListNode_freq* begin = freq_v[temp->freq][0];
        ListNode_freq* end = freq_v[temp->freq][1];
        temp->next = begin->next;
        temp->pre = begin;
        begin->next->pre = temp;
        begin->next = temp;
    }

    void update_freq(ListNode_freq* temp) {
        remove_from_freq(temp);
        temp->freq++;
        insert_to_freq(temp);
    }

    int get(int x) {
        if (kv.find(x) == kv.end()) {
            return -1;
        }
        ListNode_freq* temp = kv[x];
        update_freq(temp);

        return temp->value;
    }

    void set(int x, int y, int k) {
        // 不存在的kv映射，需要新增
        if (kv.find(x) == kv.end()) {
            ListNode_freq* temp = new ListNode_freq(x, y);
            kv[x] = temp;
            size++;
            if (size > k) {
                remove_last_node();
            }
            insert_to_freq(temp);
            traverse_map(freq_v);
        // 已经存在的映射，更新状态
        } else {
            ListNode_freq* temp = kv[x];
            temp->value = y;
            update_freq(temp);
            traverse_map(freq_v);
        }
    }

    vector<int> LFU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> result;
        for (int i = 0; i < operators.size(); i++) {
            cout << "loop: " << i << " ";
            traverse_vector(operators[i]);
            if (operators[i][0] == 1) {
                set(operators[i][1], operators[i][2], k);
            } else {
                int res = get(operators[i][1]);
                cout << "res: " << res << endl;
                result.push_back(res);
            }
            cout << "<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>" << endl;
        }

        return result;
    }
};

int main() {
    // vector<vector<int>> input {
    //     {1,1,1},{1,2,2},{1,3,2},{1,2,4},{1,3,5},{2,2},{1,4,4},{2,1}
    // };
    vector<vector<int>> input {
        {2,-788346195},{2,663130427},{2,199473611},{2,-195891979},{1,500832003,16688758},
        {2,500832003},{1,611386314,-165759898},{2,468212983},{2,-271818474},{1,652927731,-348635282},
        {1,-238995884,-258671053},{2,500832003},{2,-147772526},{1,476972438,303030386},{2,611386314},
        {2,500832003},{1,-122160324,226250640},{2,-613589387},{1,-278040308,-367610673},
        {1,225799075,-205870402},{1,-146502911,538248725},{2,225799075},{1,188913912,458810061},
        {2,-119477399},{1,-298402981,-545080319},{1,-212003183,-395967680},{1,-403828707,312998011},
        {2,-629547856},{2,-591793417},{2,-238995884},{2,-221284932},{2,612267338},{1,196500800,-910183182},
        {1,-642727487,390702112},{2,3788878},{2,225799075},{1,473983650,-454872678},{1,324437559,-590323082},
        {1,-111589492,-168572335},{2,-300599720},{1,-812965602,-161093786},{2,-642727487},{2,188913912},
        {1,-218604410,-90822424},{2,-87730129},{2,265165195},{2,-569793417},{2,-735605468},{1,333199655,133683700},
        {1,-763325900,-572482758},{1,497099029,-624508071},{2,-315061766},{2,-642727487},{2,-172489387},
        {1,-126506312,-661171046},{1,-228770667,110505831},{2,14939851},{2,225799075},{1,41839,81862151},
        {1,720095888,-829415148},{2,-107363800},{2,108111576},{1,-164464796,-50478014},{1,673800810,676579578},
        {2,333199655},{1,-376502501,520266971},{2,18123250},{2,-355618060},{1,317541429,-496924381},{1,532361869,-193819067},
        {2,-146502911},{1,13255831,215012435},{1,212786497,-259466844},{2,212786497},{2,-76179546},{1,208731547,-346426473},
        {1,-379844741,37483217},{1,418861952,-632911083},{2,590753811},{1,-182038778,99070433},{1,-255626757,-245701776},
        {2,212786497},{1,-50736696,223451417},{1,824482016,-191887185},{2,-431317093},{1,207876912,-74094350},{2,207876912},
        {1,-600453358,-39692330},{1,-246867638,-281264102},{2,-488558},{2,26726728},{2,-141826073},{1,501396780,-698492622},
        {1,740955506,-314567765},{2,356005885},{1,-34549395,-815604168},{1,418408622,176458303},{1,-426908813,496481231},
        {2,611386314},{1,65959955,169104162},{2,124436973},{2,-398619432}
    };
    int capacity = 3;
    Solution instance;
    vector<int> result = instance.LFU(input, capacity);

    traverse_vector(result);

    return 0;
}