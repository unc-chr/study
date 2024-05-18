/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM95.cpp
*   Author：leekaihua
*   Date：2023年04月25日
*   Brife：
*



*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    int candy(vector<int>& arr) {
        // write code here
        int length = arr.size();
        if (length == 1) {
            return 1;
        }
        
        int lo = 0;
        int mi = 0;
        int hi = 0;
        int i = 0;
        vector<int> candy(length, 1);
        while (i < length - 1) {
            int sum_rise = 0;
            int sum_down = 0;
            while (i < length - 1) {
                if (arr[i + 1] < arr[i]) {
                    mi = i;
                    break;
                } else if (arr[i + 1] > arr[i]) {
                    sum_rise++;
                }
                i++;
            }
            while (i < length - 1) {
                if (arr[i + 1] > arr[i]) {
                    hi = i;
                    break;
                } else if (arr[i + 1] <= arr[i]) {
                    sum_down++;
                }
                i++;
            }
            cout << "sum_rise: " << sum_rise << ", sum_down: " << sum_down << endl;
            cout << "lo: " << lo << ", mi: " << mi << ", hi: " << hi << endl;
            for (int j = hi; j > mi + 1; j--) {
                if (arr[j - 1] > arr[j]) {
                    candy[j - 1] = candy[j] + 1;
                } else if (arr[j - 1] == arr[j]) {
                    candy[j - 1] = candy[j];
                }
            }
            candy[mi] = max(max(sum_rise, sum_down), 1);
            while (arr[mi] == arr[mi - 1]) {
                candy[mi - 1] = candy[mi];
                mi--;
            }
            for (int j = lo; j < mi - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    candy[j + 1] = candy[j] + 1;
                } else if (arr[j + 1] == arr[j]) {
                    candy[j + 1] = candy[j];
                }
            }
            lo = hi;
            mi = hi;
        }
        if (arr[length - 1] == arr[length - 2]) {
            candy[length - 1] = candy[length - 2];
        } else if (arr[length - 1] > arr[length - 2]) {
            candy[length - 1] = candy[length - 2] + 1;
        }

        int result = 0;
        for (int i = 0; i < candy.size(); i++) {
            cout << candy[i] << " ";
            result += candy[i];
        }
        cout << endl;

        return result;
    }
};

int main() {
    // vector<int> arr{1,1,2};
    // vector<int> arr{4,4,4};
    vector<int> arr{1,4,2,7,9};
    Solution instance;
    int result = instance.candy(arr);
    cout << result << endl;

    return 0;
}