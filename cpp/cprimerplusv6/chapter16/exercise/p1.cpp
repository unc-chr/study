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

bool is_moslems(const std::string& str);
int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    cout << "Enter a string <q to quit>: ";
    string str;
    while (cin >> str && str != "q") {
        if (is_moslems(str)) {
            cout << "Your input: " << str << " is moslems! " << endl;
        } else {
            cout << "Your input: " << str << " is not moslems! " << endl;
        }
        cout << "---------------------------------" << endl;
        cout << "Enter another string <q to quit>: ";
    }

    return 0;
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