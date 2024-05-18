/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM22.cpp
*   Author：leekaihua
*   Date：2023年04月17日
*   Brife：
*



*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串 
     * @param version2 string字符串 
     * @return int整型
     */
    void get_modi_code(string& str, int& start, int& end) {
        for (int i = start; i < end; i++) {
            if (str[i] == '.') {
                end = i;
            }
        }
        while (str[start] == '0') {
            start++;
        }
        if (start == end - 1 && str[start] == '0') {
            start++;
        }
    }

    int compare(string version1, string version2) {
        // write code here
        int start1 = 0;
        int length1 = version1.length();
        int end1 = length1;
        int start2 = 0;
        int length2 = version2.length();
        int end2 = length2;
        while (start1 < end1 || start2 < end2) {
            get_modi_code(version1, start1, end1);
            get_modi_code(version2, start2, end2);
            int sub_str_length1 = end1 - start1 > 0 ? end1 - start1 : 0;
            int sub_str_length2 = end2 - start2 > 0 ? end2 - start2 : 0;
            if (sub_str_length1 < sub_str_length2) {
                return -1;
            } else if (sub_str_length1 > sub_str_length2) {
                return 1;
            } else {
                for (int i = 0; i < sub_str_length1; i++) {
                    if (version1[start1 + i] < version2[start2 + i]) {
                        return -1;
                    } else if (version1[start1 + i] > version2[start2 + i]) {
                        return 1;
                    }
                }
            }
            start1 = end1 + 1;
            start2 = end2 + 1;
            end1 = length1;
            end2 = length2;
        }

        return 0;
    }
};

int main() {
    string version1 = "1.0.1";
    string version2 = "1";
    Solution instance;
    int result = instance.compare(version1, version2);
    cout << result << endl;

    return 0;
}