/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：cpp70.cpp
*   Author：leekaihua
*   Date：2023年03月30日
*   Brife：
*


*/

#include<bits/stdc++.h>
#include <utility>
using namespace std;
int main(){
    set<int>s;
    //write your code here......
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp=0;
        cin>>temp;
        s.insert(temp);
    }
    //set<int>::iterator p;
    for(int i=0;i<m;i++){
        cin>>x;
        auto p = s.upper_bound(x);
        if(p != s.end()){
            cout<<*p<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
     
    return 0;
}