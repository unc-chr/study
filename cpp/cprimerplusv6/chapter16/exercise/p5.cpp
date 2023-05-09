/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p5.cpp
*   Author：leekaihua
*   Date：2023年03月18日
*   Brife：该程序参考了第4题
*

*/

#include <iostream>
#include <algorithm>

template <typename T>
int reduce(T ar[], int n);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string str_list[10] = {
        "string1", "string2", "string3", "string4", "string1",
        "string6", "string3", "string1", "string9", "string1"
    };
    long long_list[10] = {
        1, 2, 3, 4, 5, 5, 7, 3, 2, 1
    };

    int num_in_str_list = reduce(str_list, 10);
    cout << "There's " << num_in_str_list << " ele in string list." << endl;
    int num_in_long_list = reduce(long_list, 10);
    cout << "There's " << num_in_long_list << " ele in long list." << endl;

    cout << "Done! Bye!" << endl;
    return 0;
    
}

template <typename T>
int reduce(T ar[], int n) {
    // 先进行升序排列
    std::sort(ar, ar + n);
    // 然后使用unique()
    auto new_end = std::unique(ar, ar + n);
    return (new_end - ar);
}