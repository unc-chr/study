/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：cpp49.cpp
*   Author：leekaihua
*   Date：2023年03月30日
*   Brife：
*



*/

#include <iostream>
// write your code here......
#include <set>

using namespace std;

int main() {

    char str[100] = { 0 };
    cin.getline(str, sizeof(str));

    // write your code here......
    set<char> new_set;
    for (int i = 0; i < sizeof(str); i++) {
        new_set.insert(str[i]);
    }
    for (auto iter = new_set.begin(); iter != new_set.end(); iter++) {
        cout << *iter;
    }
    cout << endl;

    return 0;
}