/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：cpp54.cpp
*   Author：leekaihua
*   Date：2023年03月30日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main() {

    char str[100] = { 0 };
    cin.getline(str, sizeof(str));

    // write your code here......
    int i = 0;
    string op = "";
    while (str[i] != ' ') {
        if (isalpha(str[i])) {
            op += tolower(str[i]);
        }
        i++;
    }

    // 抽取第一个数
    string num1 = "";
    i++;
    while (str[i] != ' ') {
        num1 += str[i];
        i++;
    }
    int num1_int = 0;
    int j = 0;
    for (int k = num1.length() - 1; k > 0; k--, j++) {
        num1_int += (int(num1[k]) - 48) * pow(10, j);
    }
    if (num1[0] == '-') {
        num1_int = - num1_int;
    } else {
        num1_int += (int(num1[0]) - 48) * pow(10, j);
    }

    // 抽取第二个数
    i++;
    string num2 = "";
    while (str[i] != '\0') {
        num2 += str[i];
        i++;
    }
    int num2_int = 0;
    j = 0;
    for (int k = num2.length() - 1; k > 0; k--, j++) {
        num2_int += (int(num2[k]) - 48) * pow(10, j);
    }
    if (num1[0] == '-') {
        num2_int = - num2_int;
    } else {
        num2_int += (int(num2[0]) - 48) * pow(10, j);
    }

    if (op == "add") {
        cout << num1_int + num2_int << endl;
    } else if (op == "sub") {
        cout << num1_int - num2_int << endl;
    } else if (op == "mul") {
        cout << num1_int * num2_int << endl;
    } else if (op == "div") {
        if (num2_int == 0) {
            cout << "Error" << endl;
        } else {
            cout << num1_int / num2_int << endl;
        }
    }

    return 0;
}