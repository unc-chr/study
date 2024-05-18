/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：cpp33.cpp
*   Author：leekaihua
*   Date：2023年03月29日
*   Brife：
*



*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char str[100] = { 0 };
    char substr[100] = { 0 };

    cin.getline(str, sizeof(str));
    cin.getline(substr, sizeof(substr));

    int count = 0;

    int i = 0;
    int len_str;
    int len_sub;
    for (int i = 0; i < 100; i++) {
        if (str[i] == '\0') {
            len_str = i;
            break;
        }
    }
    for (int i = 0; i < 100; i++) {
        if (substr[i] == '\0') {
            len_sub = i;
            break;
        }
    }
    while (i < len_str) {
        if (str[i] != substr[0]) {
            i++;
            continue;
        }
        bool has_sub = true;
        
        for (int j = 0, k = i; j < len_sub && k < len_str; j++, k++) {
            if (str[k] != substr[j]) {
                has_sub = false;
                break;
            }
        }
        if (has_sub) {
            count++;
            i += len_sub;
        } else {
            i++;
        }
    }

    cout << count << endl;

    return 0;
}