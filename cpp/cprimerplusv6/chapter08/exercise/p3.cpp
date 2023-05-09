/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2021年12月26日
*   Brife：
*



*/
#include<iostream>
#include<string>

using namespace std;
void show_upper(const string& str);

int main(){
    string str;
    cout << "Enter a string (q to quit): ";
    getline(cin, str);
    while(str != "" && str != "q") {
        show_upper(str);
        cout << "Next string (q to quit):";
        getline(cin, str);
    }
}

void show_upper(const string& str) {
    char upper_str[str.size() + 1];
    upper_str[str.size()] = '\0';
    for (int i = 0; i < str.size(); i++) {
        upper_str[i] = toupper(str[i]);
    }
    cout << upper_str << endl;
}