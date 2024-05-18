/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p5.cpp
*   Author：leekaihua
*   Date：2023年03月21日
*   Brife：
*



*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>

void show_name(const std::string& name);

int main() {
    using std::cout;
    using std::cerr;
    using std::cin;
    using std::endl;
    using std::ifstream;
    using std::ofstream;
    using std::set;
    using std::vector;
    using std::string;
    
    cout << "Enter Mat's friends list filename: ";
    string file_mat_friend;
    cin >> file_mat_friend;
    cout << "Enter Pat's friends list filename: ";
    string file_pat_friend;
    cin >> file_pat_friend;

    std::ifstream fin;
    fin.open(file_mat_friend.c_str());
    if(!fin.is_open()) {
        cerr << "Could not open " << file_mat_friend << endl;
        exit(EXIT_FAILURE);
    }

    string name;
    vector<string> friend_vector_mat;
    while (getline(fin, name)) {
        if (name != "") {
            friend_vector_mat.push_back(name);
        }
    }
    if (fin.eof()) {
        cout << file_mat_friend << " terminated by eof." << endl;
    } else if (fin.fail()) {
        cout << file_mat_friend << " terminated by data mismatch or stream broken." << endl;
    } else {
        cout << file_mat_friend << " terminated by unknown reason." << endl;
    }
    // 这里需要关闭到file_mat_friend 文件的连接，关闭连接并不会删除流。
    // 流对象，输入缓冲区仍然存在。
    fin.close();
    fin.clear();

    fin.open(file_pat_friend.c_str());
    if(!fin.is_open()) {
        cerr << "Could not open " << file_pat_friend << endl;
        exit(EXIT_FAILURE);
    }
    vector<string> friend_vector_pat;
    while (getline(fin, name)) {
        if (name != "") {
            friend_vector_pat.push_back(name);
        }
    }
    if (fin.eof()) {
        cout << file_pat_friend << " terminated by eof." << endl;
    } else if (fin.fail()) {
        cout << file_pat_friend << " terminated by data mismatch or stream broken." << endl;
    } else {
        cout << file_pat_friend << " terminated by unknown reason." << endl;
    }
    fin.close();

    cout << "Mat's friend as blow: " << endl;
    for_each(friend_vector_mat.begin(), friend_vector_mat.end(), show_name);
    cout << endl;

    cout << "Mat's friend in order as blow: " << endl;
    sort(friend_vector_mat.begin(), friend_vector_mat.end());
    for_each(friend_vector_mat.begin(), friend_vector_mat.end(), show_name);
    cout << endl;

    cout << "Pat's friend as blow: " << endl;
    for_each(friend_vector_pat.begin(), friend_vector_pat.end(), show_name);
    cout << endl;

    cout << "Pat's friend in order as blow: " << endl;
    sort(friend_vector_pat.begin(), friend_vector_pat.end());
    for_each(friend_vector_pat.begin(), friend_vector_pat.end(), show_name);
    cout << endl;

    set<string> union_friend;
    copy(friend_vector_mat.begin(),
        friend_vector_mat.end(),
        std::insert_iterator<set<string> >(union_friend, union_friend.begin()));
    copy(friend_vector_pat.begin(),
        friend_vector_pat.end(),
        std::insert_iterator<set<string> >(union_friend, union_friend.begin()));
    cout << "Mat's and Pat's friend in order as blow: " << endl;
    for_each(union_friend.begin(), union_friend.end(), show_name);
    cout << endl;

    cout << "Done!" << endl;
    return 0;

}

void show_name(const std::string& name) {
    std::cout << name << " | ";
}