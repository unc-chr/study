/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：textin1.cpp
*   Author：leekaihua
*   Date：2021年12月07日
*   Brife：
*



*/
#include <iostream>

int main(){
    using namespace std;
    char ch;
    int count = 0;
    cout << "Enter character; enter # to quit:\n";
    cin >> ch;
    cout << "First character read: " << ch << endl;
    cin >> ch;
    cout << "Second character read: " << ch << endl;
    
    while (ch != '#') {
        cout << ch;
        cout << " loop time" << endl;
        ++count;
        cin >> ch;
    }
    cout << endl << count << " characters read\n";

    return 0;
}