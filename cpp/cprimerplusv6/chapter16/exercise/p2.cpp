/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.  *   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2023年03月18日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <cctype>

bool is_moslems(const std::string& str);
std::string refine(const std::string& str);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    cout << "Enter a string <q to quit>: ";
    string str;
    string refined_str;
    getline(cin, str);
    while (str != "q") {
        refined_str = refine(str);
        cout << "Your input refine: " << refined_str << endl;
        if (is_moslems(refined_str)) {
            cout << "Your input: " << str << " is moslems! " << endl;
        } else {
            cout << "Your input: " << str << " is not moslems! " << endl;
        }
        cout << "---------------------------------" << endl;
        cout << "Enter another string <q to quit>: ";
        getline(cin, str);
    }

    return 0;
}

std::string refine(const std::string& str) {
    std::string refined_str;
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (!isalpha(str[i])) {
            continue;
        }
        refined_str += tolower(str[i]);
    }

    return refined_str;
}

bool is_moslems(const std::string& str) {
    int len = str.size();
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }

    return true;
}