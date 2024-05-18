/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB35.cpp
*   Author：leekaihua
*   Date：2023年04月30日
*   Brife：
*



*/

#include <iostream>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
public:
    int minTrace(vector<vector<int> >& triangle) {
        // write code here
        int length = triangle.size();
        vector<vector<int>> path(length, vector<int>(length, 0));
        path[0][0] = triangle[0][0];
        for (int i = 1; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (j - 1 >= 0 && j <= i - 1) {
                    path[i][j] = 
                            min(path[i - 1][j - 1], path[i - 1][j]) 
                            + triangle[i][j];
                } else if (j > i - 1) {
                    path[i][j] = path[i - 1][j - 1] + triangle[i][j];
                } else if (j - 1 < 0) {
                    path[i][j] = path[i - 1][j] + triangle[i][j];
                }
            }
        }

        traverse_vector_vector(path);
        std::cout << "length: " << length << std::endl;
        for (int i = 0; i < length; i++) {
            std::cout << "i: " << i << ", size: " << triangle[i].size() << std::endl;
        }

        int result = path[length - 1][0];
        for (int i = 1; i < length; i++) {
            if (path[length - 1][i] < result) {
                result = path[length - 1][i];
            }
        }
        std::cout << "here" << std::endl;
        std::cout << "result: " << result << std::endl;

        return result;
    }
};

int main() {
    /// vector<vector<int>> triangle {
    ///     {2},{3,4},{6,5,7},{4,2,8,3}
    /// };
    vector<vector<int>> triangle {
        {1},
        {1,2},
        {1,2,3},
        {1,2,3,4},
        {1,2,3,4,5},
        {1,2,3,4,5,6},
        {1,2,3,4,5,6,7},
        {1,2,3,4,5,6,7,8}
        // {0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    Solution instance;
    int result = instance.minTrace(triangle);
    std::cout << "end" << std::endl;
    std::cout << result << std::endl;

    return 0;
}