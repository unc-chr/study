/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB25.cpp
*   Author：leekaihua
*   Date：2023年05月04日
*   Brife：
*



*/

#include <cctype>
#include <iostream>
#include <vector>
#include <string>

#include "ads.h"

using namespace std;

class Time_self {
    private:
        int h1;
        int h2;
        int m1;
        int m2;
        int to_minutes(const Time_self& t) {
            vector<int> digit_h1;
            if (t.h1 != -1) {
                digit_h1.push_back(h1);
            } else (
                digit_h1.push
            )
        }
    public:
        Time_self(const vector<int>& digits) {
            this->h1 = digits[0];
            this->h2 = digits[1];
            this->m1 = digits[2];
            this->m2 = digits[3];
        }

        Time_self(int h1, int h2, int m1, int m2) {
            this->h1 = h1;
            this->h2 = h2;
            this->m1 = m1;
            this->m2 = m2;
        }

        Time_self max_time() {
            int n_h1 = h1 == -1 ? 2 : h1;
            int n_m1 = m1 == -1 ? 5 : m1;
            int n_m2 = m2 == -1 ? 9 : m2;
            int n_h2 = h2;
            if (h2 == -1) {
                if (n_h1 == 2) {
                    n_h2 = 3;
                } else {
                    n_h2 = 9;
                }
            }

            return Time_self(n_h1, n_h2, n_m1, n_m2);
        }

        Time_self min_time() {
            int n_h1 = h1 == -1 ? 0 : h1;
            int n_m1 = m1 == -1 ? 0 : m1;
            int n_m2 = m2 == -1 ? 0 : m2;
            int n_h2 = h2 == -1 ? 0 : h2;

            return Time_self(n_h1, n_h2, n_m1, n_m2);
        }

        // 计算时间t2 - t1 的最小值
        friend int diff(const Time_self& t1, const Time_self& t2) {

        }

        friend int operator-(const Time_self& t1, const Time_self& t2) {
            int minute_t1 = t1.h1 * 60 * 10 + t1.h2 * 60 + t1.m1 * 10 + t1.m2;
            int minute_t2 = t2.h1 * 60 * 10 + t2.h2 * 60 + t2.m1 * 10 + t2.m2;
            return minute_t1 - minute_t2;
        }

        friend ostream& operator<<(ostream& cout, const Time_self& t) {
            cout << t.h1 << t.h2 << ":" << t.m1 << t.m2 << endl;
            return cout;
        }
        
};

int main() {
    string input;
    vector<Time_self> time_input;
    vector<int> index {0, 1, 3, 4};
    vector<int> digits;

    for (int i = 0; i < 2; i++) {
        getline(cin, input);
        digits.clear();
        for (int j = 0; j < index.size(); j++) {
            if (isdigit(input[index[j]])) {
                digits.push_back(input[index[j]] - 48);
            } else {
                digits.push_back(-1);
            }
        }
        traverse_vector(digits);
        time_input.push_back(Time_self(digits));
    }

    cout << time_input[1].max_time();
    cout << time_input[0].min_time();
    cout << time_input[1].min_time();
    cout << time_input[0].max_time();
    int diff_max = time_input[1].max_time() - time_input[0].min_time();
    int diff_min = time_input[1].min_time() - time_input[0].max_time();
    cout << diff_min << " " << diff_max << endl;

    return 0;
}