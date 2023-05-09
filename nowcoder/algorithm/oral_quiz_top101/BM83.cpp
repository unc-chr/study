/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM83.cpp
*   Author：leekaihua
*   Date：2023年04月14日
*   Brife：
*



*/

#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

class Solution {
public:
    string trans(string s, int n) {
        // write code here
        // 大小写转换
        for (int i = 0; i < n; i++) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
            } else if (islower(s[i])) {
                s[i] = toupper(s[i]);
            } else {
                continue;
            }
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            cout << i << ": " << s[i] << endl;
        }
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] != ' ') {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);
            cout << "reverse part i:" << i << " j: " << j << ", s: " << s << endl;
            i = j;
        }

        return s;
    }
};

int main() {
    Solution instance;
    string ori = " h i";
    string result = instance.trans(ori, 4);
    cout << result << endl;

    return 0;
}