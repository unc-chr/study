/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p4.cpp
*   Author：leekaihua
*   Date：2021年12月09日
*   Brife：
*



*/
#include<iostream>

using namespace std;
void show_menu();
int main(){
    const int strsize = 20;
    struct bop {
        char fullname[strsize];
        char title[strsize];
        char bopname[strsize];
        int preference;
    };

    bop bop_array[5] = {
        {"Wimp Macho", "engineer", "WM", 0},
        {"Raki Rhodes", "Junior Programmer", "RR", 1},
        {"Celia Laiter", "polit", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "HH", 1},
        {"Pat Hand", "teacher", "LOOPY", 2},
    };

    bool need_exit = false;
    char ch;
    show_menu();
    cout << "Enter your choice: ";
    while (cin >> ch) {
        if (ch == 'q') {
            cout << "Bye!" << endl;
            break;
        }
        switch (ch) {
            case 'a':
                for (int i = 0; i < 5; i++) {
                    cout << bop_array[i].fullname << endl;
                }
                break;
            case 'b':
                for (int i = 0; i < 5; i++) {
                    cout << bop_array[i].title<< endl;
                }
                break;
            case 'c':
                for (int i = 0; i < 5; i++) {
                    cout << bop_array[i].bopname<< endl;
                }
                break;
            case 'd':
                for (int i = 0; i < 5; i++) {
                    int prefer = bop_array[i].preference;
                    if (prefer == 0) {
                        cout << bop_array[i].fullname << endl;
                    } else if (prefer == 1) {
                        cout << bop_array[i].title << endl;
                    } else {
                        cout << bop_array[i].bopname << endl;
                    }
                }
                break;
            default:
                break;
        }
        cout << "Next choice: ";
    }
    return 0;
}

void show_menu(){
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name           b. display by title" << endl;
    cout << "c. display by bopname        d. display by preference" << endl;
    cout << "q. quit" << endl;
}