/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_string.cpp
*   Author：leekaihua
*   Date：20240702
*   Brife：
*



*/
#include <cstring>
#include <iostream>

#if 0
#include <string>
using std::string;
#endif

#if 1
#include "string.h"
using lee::stl::string;
#endif

using std::cout;
using std::endl;

int main() {
    // default constructor
    string str;
    std::cout << "str: " << str << std::endl;
    // construct with const char*
    string str2 = "aaa";
    string str3 = "bbb";
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;
    // overload operator + and accept argu string
    string str4 = str2 + str3;
    std::cout << "str4 :" << str4 << std::endl;
    // overload operator + and accept argu const char*
    string str5 = str2 + "ccc";
    std::cout << "str5: " << str5 << std::endl;
    // friend overload operator +
    // two arguments are const char* and string
    string str6 = "ddd" + str2;
    std::cout << "str6: " << str6 << std::endl;

    // friend function overload operator << 
    cout << "str6: " << str6 << endl;
    // overload operator ==
    if (str2 == str3) {
        cout << str2 << " == " << str3 << endl;
    }
    // overload operator >
    if (str5 > str6) {
        cout << str5 << " > " << str6 << endl;
    } else {
        cout << str5 << " <= " << str6 << endl;
    }
    int len = str6.length();
    for (int i = 0; i < len; ++i) {
        cout << str6[i] << " ";
    }
    cout << endl;

    // convert string to char*
    char buf[1024] = {0};
    strcpy(buf, str6.c_str());
    cout << "buf: " << buf << endl;

    // test iterator
    // string::iterator iter = str6.begin();
    for (auto iter = str6.begin(); iter != str6.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    // test iterator with for each
    for (char ch : str6) {
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}