/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2021年12月09日
*   Brife：
*



*/
#include<iostream>

using namespace std;
void print_menu();

int main(){
    char ch;
    bool is_selected = false;
    while (cin >> ch) {
        cout << "here ch: " << ch << endl;
        switch (ch)
        {
        case 'c':
            cout << "A maple is a carnivore." << endl;
            is_selected = true;
            break;
        case 'p':
            cout << "A maple is a pianist." << endl;
            is_selected = true;
            break;
        case 't':
            cout << "A maple is a tree." << endl;
            is_selected = true;
            break;
        case 'g':
            cout << "A maple is a game." << endl;
            is_selected = true;
            break;
        default:
            print_menu();
            break;
        }
        if (is_selected) {
            break;
        }
    }

    return 0;
}

void print_menu(){
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore              p) pianist" << endl;
    cout << "t) tree                   g) game" << endl;
}