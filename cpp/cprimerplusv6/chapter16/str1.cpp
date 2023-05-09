/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：str1.cpp
*   Author：leekaihua
*   Date：2022年03月01日
*   Brife：
*



*/

#include <iostream>
#include <string>

int main() {
    using namespace std;

    string one("Lottery Winner!");
    cout << one << endl;

    string two(20, '$');
    cout << two << endl;

    string three(one);
    cout << three << endl;

    one += " Oops!";
    cout << one << endl;

    two = "Sorry!  That was ";
    three[0] = 'P';

    string four;
    four = two + three;
    cout << four << endl;

    char alls[] = "All's well that ends well";
    string five(alls, 20);
    cout << five << endl;

    // 这里将输出字符串后内存中的内容，具体内容是不确定的。
    string test(alls, 40);
    cout << test << endl;

    string six(alls + 6, alls + 10);
    cout << six << endl;

    string seven(&five[6], &five[10]);
    cout << seven << "...\n";

    string eight(four, 7, 16);
    cout << eight << " in motion!" << endl;

    return 0;
}