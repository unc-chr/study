/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p8.cpp
*   Author：leekaihua
*   Date：2023年03月18日
*   Brife：
*



*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iterator>

void show_string(const std::string& str);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::vector;
    using std::set;
    using std::string;

    cout << "Mat, enter your friends' name (done for end): " << endl;
    string input_name;
    vector<string> mat_friends;
    getline(cin, input_name);
    while (input_name != "done" && input_name != "") {
        mat_friends.push_back(input_name);
        cout << "Enter another: ";
        getline(cin, input_name);
    }

    cout << "Pat, enter your friends' name (done for end): " << endl;
    vector<string> pat_friends;
    getline(cin, input_name);
    while (input_name != "done" && input_name != "") {
        pat_friends.push_back(input_name);
        cout << "Enter another: ";
        getline(cin, input_name);
    }

    cout << "Here are Mat's friends: " << endl;
    for_each(mat_friends.begin(), mat_friends.end(), show_string);
    cout << endl;

    cout << "Here are Pat's friends: " << endl;
    for_each(pat_friends.begin(), pat_friends.end(), show_string);
    cout << endl;

    cout << "Here are Mat's friends in order: " << endl;
    sort(mat_friends.begin(), mat_friends.end());
    for_each(mat_friends.begin(), mat_friends.end(), show_string);
    cout << endl;

    cout << "Here are Pat's friends in order: " << endl;
    sort(pat_friends.begin(), pat_friends.end());
    for_each(pat_friends.begin(), pat_friends.end(), show_string);
    cout << endl;

    set<string> union_friends;
    std::insert_iterator<set<string>> insert_iter(union_friends, union_friends.begin());
    copy(mat_friends.begin(), mat_friends.end(), insert_iter);
    copy(pat_friends.begin(), pat_friends.end(), insert_iter);

    cout << "Here are Mat and Pat all friends in order: " << endl;
    for_each(union_friends.begin(), union_friends.end(), show_string);
    cout << endl;

    cout << "Done!" << endl;

    return 0;
}

void show_string(const std::string& str) {
    std::cout << str << " | ";
}