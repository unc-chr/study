/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p8.cpp
*   Author：leekaihua
*   Date：2021年12月09日
*   Brife：
*



*/
#include<iostream>
#include<fstream>
#include<cstdlib>

int main(){
    using namespace std;
    ifstream input_file;
    input_file.open("input_for_p8");
    if (!input_file) {
        cout << "Could not open file" << endl;
        exit(EXIT_FAILURE);
    }

    char ch;
    int i = 0;
    while (input_file.good()) {
        input_file >> ch;
        i++;
    }
    cout << "file inclubde " << i << " characters." << endl;

    return 0;
}