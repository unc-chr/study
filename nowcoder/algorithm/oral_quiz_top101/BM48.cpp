/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM48.cpp
*   Author：leekaihua
*   Date：2023年04月23日
*   Brife：
*



*/

#include <iostream>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
    private:
        vector<int> nums_sort;
        int partition(int lo, int hi) {
            int pivot = nums_sort[hi];
            while (lo < hi) {
                while (lo < hi && nums_sort[lo] <= pivot) {
                    lo++;
                }
                nums_sort[hi] = nums_sort[lo];
                while (lo < hi && nums_sort[hi] >= pivot) {
                    hi--;
                }
                nums_sort[lo] = nums_sort[hi];
            }
            nums_sort[lo] = pivot;

            return lo;
        }

        int get_index_k(int k) {
            int lo = 0;
            int hi = nums_sort.size() - 1;
            int index_located = 0;
            while (lo <= hi) {
                index_located = partition(lo, hi);
                if (index_located == k) {
                    return nums_sort[k];
                } else if (index_located < k) {
                    lo = index_located + 1;
                } else {
                    hi = index_located - 1;
                }
            }

            return nums_sort[index_located];
        }

    public:
        void Insert(int num) {
            nums_sort.push_back(num);
            traverse_vector(nums_sort);
        }

        double GetMedian() { 
            int length = nums_sort.size();
            if (length % 2 == 1) {
                int result = get_index_k(length / 2);
                return result;
            } else {
                int result1 = get_index_k(length / 2);
                int result2 = get_index_k(length / 2 - 1);
                return double(result1 + result2) / 2;
            }
        }

};

int main() {
    vector<int> a {5,2,3,4,1,6,7,0,8};
    Solution instance;
    for (int i = 0; i < a.size(); i++) {
        instance.Insert(a[i]);
        double me = instance.GetMedian();
        cout << me << endl;
    }

    return 0;
}