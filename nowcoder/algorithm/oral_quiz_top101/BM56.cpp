/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：BM55.cpp
*   Author：leekaihua
*   Date：2023年04月20日
*   Brife：
*



*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "ads.h"

using namespace std;

class Solution {
public:
    void recursion(vector<vector<int> > &res, vector<int> &num, vector<int> &temp, vector<int> &vis){
        //临时数组满了加入输出
        if(temp.size() == num.size()){ 
            res.push_back(temp);
            return;
        }
        //遍历所有元素选取一个加入
        for(int i = 0; i < num.size(); i++){ 
            //如果该元素已经被加入了则不需要再加入了
            if(vis[i]) 
                continue;
            if(i > 0 && num[i - 1] == num[i] && !vis[i - 1]) 
                //当前的元素num[i]与同一层的前一个元素num[i-1]相同且num[i-1]已经用过了
                continue;  
            //标记为使用过
            vis[i] = 1;  
            //加入数组
            temp.push_back(num[i]); 
            recursion(res, num, temp, vis);
            //回溯
            vis[i] = 0; 
            temp.pop_back();
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        //先按字典序排序
        sort(num.begin(), num.end()); 
        //标记每个位置的元素是否被使用过
        vector<int> vis(num.size(), 0); 
        vector<vector<int> > res;
        vector<int> temp; 
        //递归获取
        recursion(res, num, temp, vis); 
        return res;
    }
};


int main() {
    // vector<int> num {1,2,3,4};
    // vector<int> num {1,2,2,4};
    vector<int> num {2,2,3,4};
    Solution instance;
    auto result = instance.permuteUnique(num);

    cout << endl;
    traverse_vector_vector(result);
    cout << result.size() << endl;

    return 0;
}