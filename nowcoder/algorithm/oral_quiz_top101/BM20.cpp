/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM20.cpp
*   Author：leekaihua
*   Date：2023年04月17日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 合并两个已经排序的数组
    void merge(vector<int>& data, int lo, int mi, int hi, int& count) {
        // 备份低位区间的元素
        vector<int> temp (mi - lo, 0);
        for (int i = lo; i < mi; i++) {
            temp[i - lo] = data[i];
        }
        for (int i = 0, j = mi, k = lo; i < mi - lo || j < hi;) {
            if ((i < mi - lo) && (j >= hi || temp[i] < data[j])) {
                data[k++] = temp[i++];
            }
            if ((j < hi) && (i >= mi - lo || temp[i] > data[j])) {
                data[k++] = data[j++];
                count += (mi - lo - i);
                count %= 1000000007;
            }
        }
    }

    // 归并排序的主算法，负责实现递归
    void merge_sort(vector<int>& data, int lo, int hi, int& count) {
        if (hi - lo < 2) {
            return;
        }

        int mi = (hi + lo) / 2;
        merge_sort(data, lo, mi, count);
        merge_sort(data, mi, hi, count);
        merge(data, lo, mi, hi, count);
    }


    int InversePairs(vector<int> data) {
        int length = data.size();
        if (length == 0) {
            return 0;
        }
        int lo = 0;
        int hi = length;
        int count = 0;
        merge_sort(data, lo, hi, count);
        return count;
    }
};

int main() {
    Solution instance;
    vector<int> data {1,2,3,4,5,6,7,0};
    int result = instance.InversePairs(data);
    cout << result << endl;

    return 0;
}