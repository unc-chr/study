/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM90.cpp
*   Author：leekaihua
*   Date：2023年04月25日
*   Brife：
*



*/

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    bool check(map<char, int>& char_count) {
        for (auto iter = char_count.begin(); iter != char_count.end(); iter++) {
            if (iter->second < 0) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string S, string T) {
        // write code here
        map<char, int> char_count;
        for (int i = 0; i < T.length(); i++) {
            char_count[T[i]] -= 1;
        }
        int lo = 0;
        int hi = 0;
        int left = -1;
        int right = -1;
        int dis = S.length() + 1;
        for (; hi < S.length(); hi++) {
            if (char_count.find(S[hi]) == char_count.end()) {
                continue;
            }
            char_count[S[hi]] += 1;
            cout << "fuck" << endl;
            while (check(char_count)) {
                cout << "lo: " << lo << ",hi: " << hi << endl;
                cout << S.substr(lo, hi - lo + 1) << ": ";
                for (auto iter = char_count.begin(); iter != char_count.end(); iter++) {
                    cout << iter->second << " ";
                }
                cout << endl;
                if (dis > hi - lo + 1) {
                    dis = hi - lo + 1;
                    left = lo;
                    right = hi;
                }
                if (char_count.find(S[lo]) != char_count.end()) {
                    char_count[S[lo]] -= 1;
                }
                lo++;
            }
        }

        if (left == -1) {
            return "";
        }
        return S.substr(left, right - left + 1);
    }
};

int main() {
    // string S = "wyqaalfdtavrmkvrgbrmauenibfxrzjpzzqzlveexayjkvdsyueboloymtvfugvtgnutkyzhaztlvwdvqkwgvmejhbpdimwqbslnrkutkpehnkefwblrprcxvtaffzxitivmssgehklvwqastojihmhcfkhnlexemtrhnxlujxrgpuyiikspycufodubisfwnydaxrwhqqpfkppuzjlzlfhbjbcttkriixkiohpexgjjvafxjqyvyfyjhbccltlvsvdgeumdavoyxtvhmtekzctidxkqsxmlvrrzmefobtmznhizdmlcoemudwkvuyirscqegvsjrfkgoshrgsvvyhrbgdycehtwjlcrjucabpgsjnjqhhnfqeiwhgalptjyflpoiuqjjwdslpiswvxobfljnnwdhgdortezpulysoqddbxbwuqabdjqqhtzpxpjsvkjrvhjmzoralvzhlzkqkbgrwijvzspvcymafymfmfhaaghnfsdrvmlruuntmcqqbdqideprkxrmfbanvfeqrphnlwjxbzqcegmhnczxbslitnvotaemroadkjclksppzeyoiznlsytnopchritiyvlleqypiqgjugxeikpclipzxtgoebxcxkpdaoulecuajueretvpbkqbgwrkaooxbeaduvoaxlaifgblzwdcjtfpsxbsnrrovturokrovtycbcqcytfjomygj";
    // string T = "baxtr";
    string S = "ehnkefwblrprcxvtaffzx";
    string T = "baxtr";
    // string S = "XDOYEZODEYXNZ";
    // string T = "XYZ";
    Solution instance;
    string result = instance.minWindow(S, T);

    cout << result << endl;

    return 0;
}