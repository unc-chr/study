/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p4.cpp
*   Author：leekaihua
*   Date：2023年03月18日
*   Brife：
*

改程序参考了程序 16.18
*/

#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

int reduce(long ar[], int n);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::vector;

    vector<long> num_list;
    int len_num_list;
    long ele_num;

    cout << "Ready to enter your long number list? <y/n>: ";
    char is_go_on;
    cin >> is_go_on;
    while (tolower(is_go_on) == 'y') {
        // 循环读取输入数字
        cout << "Enter your number here: ";
        while (cin >> ele_num) {
            num_list.push_back(ele_num);
        }

        // 重置cin错误标记
        cin.clear();
        // 删除错误输入
        while (cin.get() != '\n') {
            continue;
        }

        len_num_list = num_list.size();
        long ar[len_num_list];
        for (int i = 0; i < len_num_list; i++) {
            ar[i] = num_list[i];
        }
        int uni_num = reduce(ar, len_num_list);
        cout << "Your input long number list has " << uni_num << " elements." << endl;

        cout << "Do you want to go on? <y/n>: ";
        cin >> is_go_on;
    }

    cout << "Done! Bye!" << endl;

    return 0;
    
}

int reduce(long ar[], int n) {
    using std::vector;
    vector<long> num_list(ar, ar + n);
    // 先进行升序排列
    sort(num_list.begin(), num_list.end());
    // 然后使用unique()
    vector<long>::iterator new_end = unique(num_list.begin(), num_list.end());
    int num_of_uni = new_end - num_list.begin();
    return num_of_uni;
}