/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB30.cpp
*   Author：leekaihua
*   Date：2023年04月29日
*   Brife：
*



*/

#include <iostream>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int lo, int mi, int hi) {
        cout << "merge before, ";
        cout << "lo: " << lo << ", mi: " << mi << ", hi: " << hi << endl;
        traverse_vector(arr);
        vector<int> left_range(arr.begin() + lo, arr.begin() + mi);
        cout << "backup left range: ";
        traverse_vector(left_range);
        int i = 0;
        int j = mi;
        for (int k = lo; k < hi;) {
            if (i < mi - lo && (j >= hi || left_range[i] <= arr[j])) {
                cout << "1:" << i << "<" << mi - lo << " && " << j << ">=" << hi << " || "
                        << left_range[i] << "<=" << arr[j] << " ";
                cout << arr[k] << "=" << left_range[i] << endl;
                arr[k++] = left_range[i++];
            }
            if (j < hi && (i >= mi - lo || arr[j] <= left_range[i])) {
                cout << "2:" << j << "<" << hi << " && " << i << ">=" << mi - lo << " || "
                        << arr[j] << "<=" << left_range[i] << " ";
                cout << arr[k] << "=" << arr[j] << endl;
                arr[k++] = arr[j++];
            }
        }
        cout << "merge after, ";
        cout << "lo: " << lo << ", mi: " << mi << ", hi: " << hi << endl;
        traverse_vector(arr);
    }

    void merge_sort(vector<int>& arr, int lo, int hi) {
        if (hi - lo <= 1) {
            return;
        }
        int mi = (hi + lo) / 2;
        cout << "lo: " << lo << ", mi: " << mi << endl;
        merge_sort(arr, lo, mi);
        cout << "mi: " << mi << ", hi: " << hi << endl;
        merge_sort(arr, mi, hi);
        merge(arr, lo, mi, hi);
    }
    vector<int> MySort(vector<int>& arr) {
        // write code here
        if (arr.size() < 2) {
            return arr;
        }
        merge_sort(arr, 0, arr.size());
        return arr;
    }
};

int main() {
    vector<int> input {5,2,3,1,4};
    Solution instance;
    vector<int> result = instance.MySort(input);
    traverse_vector(result);

    return 0;
}