/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM18.cpp
*   Author：leekaihua
*   Date：2023年04月16日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int length_row = array.size();
        if (length_row == 0) {
            return false;
        }

        int length_col = array[0].size();
        if (length_col == 0) {
            return false;
        }

        cout << "row: " << length_row << ", col: " << length_col << endl;
        int up = 0;
        int down = length_row - 1;
        int left = 0;
        int right = length_col - 1;
        while (up <= down && left <= right) {
            int lo = left;
            int hi = right + 1;
            while (lo + 1 < hi) {
                int mi = (hi + lo) / 2;
                if (target < array[up][mi]) {
                    hi = mi;
                } else {
                    lo = mi;
                }
            }
            if (array[up][lo] == target) {
                return true;
            }
            right = lo;
            cout << "right: " << right << ", ";

            lo = up;
            hi = down + 1;
            while (lo + 1 < hi) {
                int mi = (hi + lo) / 2;
                if (target < array[mi][right]) {
                    hi = mi;
                } else {
                    lo = mi;
                }
            }
            if (array[lo][right] == target) {
                return true;
            }
            up = lo + 1;
            cout << "up: " << up;
            cout << endl;
        }

        return false;
    }
};

int main() {
    // vector<vector<int>> array {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    // vector<vector<int>> array {{1,2,8,9},{2,4,9,12},{4,6,10,13},{7,9,11,15}};
    vector<vector<int>> array {{1,1}};
    Solution instance;
    bool result = instance.Find(7, array);
    cout << "result: " << result << endl;
    // vector<vector<int>> array {{}}; 
    // cout << array.size() << endl;
    // if (array.size() > 0) {
    //     cout << array[0].size() << endl;
    // }


    return 0;
}