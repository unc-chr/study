/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：test_find.cpp
*   Author：leekaihua
*   Date：2023年03月19日
*   Brife：
*



*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;
    vector<int> int_list;
    for (int i = 0; i < 20; i++) {
        int_list.push_back(i);
    }

    random_shuffle(int_list.begin(), int_list.end());
    for (auto pr = int_list.begin(); pr != int_list.end(); pr++) {
        cout << *pr << " ";
    }

    auto result = find(int_list.begin(), int_list.end(), 11);
    if (result != int_list.end()) {
        cout << "got" << endl;
    }

    return 0;
}
