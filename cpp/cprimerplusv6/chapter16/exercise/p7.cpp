/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p7.cpp
*   Author：leekaihua
*   Date：2023年03月18日
*   Brife：
*



*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Lotto(int num_total, int num_selected);
void show(int ele);
bool is_OK(int num_total, int num_selected);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::vector;

    int num_total;
    int num_select;
    cout << "Enter total dot number and selected num: ";
    while(cin >> num_total >> num_select) {
        if (!is_OK(num_total, num_select)) {
            cout << "have another try: ";
            continue;
        }
        vector<int> select_dot = Lotto(num_total, num_select);
        cout << "Selected output: ";
        for_each(select_dot.begin(), select_dot.end(), show);
        // for (auto pr = select_dot.begin(); pr != select_dot.end(); i++) {
        //     cout << *pr << " ";
        // }
        cout << endl;
        cout << "have another try: ";
    }

    cout << "Done!" << endl;

    return 0;
}

std::vector<int> Lotto(int num_dot, int num_select) {
    std::vector<int> dot_series;
    std::vector<int> dot_selected;
    for (int i = 1; i < num_dot + 1; i++) {
        dot_series.push_back(i);
    }
    while(dot_selected.size() < num_select) {
        random_shuffle(dot_series.begin(), dot_series.end());
        int first_ele = dot_series[0];
        if (find(dot_selected.begin(), dot_selected.end(), first_ele) == dot_selected.end()) {
            dot_selected.push_back(first_ele);
        }
    }

    return dot_selected;
    
}

bool is_OK(int num_total, int num_selected) {
    if (num_total < 2 || num_selected < 0) {
        std::cout << "Input error: " << "input number must be positive."
            << " And total number must greater than 1." << std::endl;
        return false;
    }
    if (num_total <= num_selected) {
        std::cout << "Input error: total " << num_total << " < " << " selected "
            << num_selected << std::endl;
        return false;
    }
    return true;
}

void show(int ele) {
    std::cout << ele << " ";
}