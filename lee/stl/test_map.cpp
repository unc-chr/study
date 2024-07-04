/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_map.cpp
*   Author：mayi
*   Date：20240704
*   Brife：
*



*/
#if 1
#include <map>
#include <unordered_map>
using std::map;
using std::unordered_map;
#endif

#if 0
#include "map.h"
using lee::stl::map;
#endif

#include <cassert>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void test_unordered_map_app1() {
    const int array_size = 1000;
    int num[array_size] = {0};
    for (int i = 0; i < array_size; i++) {
        num[i] = rand() % 10 + 1;
    }
    unordered_map<int, int> num_count;
    for (int i = 0; i < array_size; i++) {
        // num_count[num[i]]++;
        // following code could be replace by upper code line.
        // if num[i] not in num_count, then create pair {num[i], 0}
        // if num[i] exist, then ++
        if (num_count.find(num[i]) == num_count.end()) {
            num_count[num[i]] = 1;
        } else {
            num_count[num[i]]++;
        }
    }
    for (auto item : num_count) {
        cout << item.first << ":" << item.second << endl;
    }
}

void test_unordered_map() {
    // test constructor
    unordered_map<int, string> map1;
    // test insert
    map1.insert(std::make_pair(1000, "zhangsan"));
    map1.insert({1001, "lisi"});
    map1.insert({1002, "wangwu"});
    // test insert duplicated key
    map1.insert({1000, "zhangsi"});
    // test size
    cout << map1.size() << endl;
    // test operator[]
    // operator[key] has side effect, if key not existed in map
    // a pair {key, V()} will be insert, value is created with
    // type V default construtor.
    cout << map1[1000] << endl;
    map1[1005];
    map1[1006] = "zhaoliu";
    map1[1000] = "zhangsan_v2";
    for (auto iter = map1.begin(); iter != map1.end(); iter++) {
        cout << iter->first << "->" << iter->second << endl;
    }
    cout << endl;
    // test erase
    map1.erase(1002);
}

void test_map() {

}

int main() {
    // test_unordered_map();
    // test_unordered_map_app1();
    // test_unordered_multimap();
    test_map();
    // test_multimap();
    return 0;
}