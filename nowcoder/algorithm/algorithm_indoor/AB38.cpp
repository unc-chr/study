/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB38.cpp
*   Author：leekaihua
*   Date：2023年04月30日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <vector>

#include "ads.h"

using namespace std;

int lcs(string s1, string s2) {
    vector<int> dp1(s2.length() + 1, 0);
    vector<int> dp2(s2.length() + 1, 0);
    traverse_vector(dp2);
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 1; j < s2.length() + 1; j++) {
            if (s1[i] == s2[j - 1]) {
                dp2[j] = dp1[j - 1] + 1; 
            } else {
                dp2[j] = max(dp1[j], dp2[j - 1]);
            }
        }
        for (int j = 0; j < s2.length() + 1; j++) {
            dp1[j] = dp2[j];
        }
        traverse_vector(dp2);
    }

    return dp2[s2.length()];
}

int main() {
    int len1;
    int len2;
    cin >> len1;
    cin >> len2;
    string s1;
    string s2;
    if (len1 > len2) {
        cin >> s1;
        cin >> s2;
    } else {
        cin >> s2;
        cin >> s1;
    }
    int result = lcs(s1, s2);
    cout << result << endl;

    return 0;
}
