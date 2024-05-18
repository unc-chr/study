/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2021年12月31日
*   Brife：
*



*/
#include <iostream>
#include <string>

void strcount(const std::string&);
int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    std::string input;
    cout << "Enter a line: ";
    getline(cin, input);
    while (input != "") {
        strcount(input);
        cout << "Enter next line(empty line to quit):\n";
        getline(cin, input);
    }

    cout << "Bye!" << endl;
    return 0;
}

void strcount(const std::string& str) {
    using std::cin;
    using std::cout;
    using std::endl;
    static int total = 0;
    int count = 0;

    cout << "\"" << str << "\" contains ";
    int length_str = str.size();
    total += length_str;
    cout << length_str << " characters\n";
    cout << total << " characters total\n";
}