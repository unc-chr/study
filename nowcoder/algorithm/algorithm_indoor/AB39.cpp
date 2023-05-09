/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB39.cpp
*   Author：leekaihua
*   Date：2023年05月01日
*   Brife：
*



*/

#include <algorithm>
#include <iostream>
#include <vector>
#include "ads.h"

using namespace std;

int calcu(vector<int>& volumes, int volume) {
    sort(volumes.begin(), volumes.end());
    traverse_vector(volumes);

    int hi = 0;
    int lo = 0;
    int sum_volume = volumes[0];
    int result = 0;
    while (hi < volumes.size()) {
        if (sum_volume <= volume) {
            cout << "sum_volume: " << sum_volume << endl;
            if (result < sum_volume) {
                result = sum_volume;
            }
            hi++;
            sum_volume += volumes[hi];
        } else {
            sum_volume -= volumes[lo];
            lo++;
        }
    }

    return result;
}

int main() {
    int volume = 100;
    int n = 16;
    // cin >> volume;
    // cin >> n;
    vector<int> volumes {16,3,5,16,16,16,16,16,16,16,16,16,16,16,16,16};
    // for (int i = 0; i < n; i++) {
    //     cin >> volumes[i];
    // }

    int result = calcu(volumes, volume);
    cout << volume - result << endl;

    return 0;
}