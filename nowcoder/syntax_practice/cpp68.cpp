/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：cpp69.cpp
*   Author：leekaihua
*   Date：2023年03月30日
*   Brife：
*



*/

#include<bits/stdc++.h>
#include<iterator>
#include<set>
using namespace std;
int main(){
	set<int>s;
	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
        cout << temp << " ";
		s.insert(temp);
	}
    cout << endl;
    cout << s.size() << endl;
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	}
	
	return 0;
}

