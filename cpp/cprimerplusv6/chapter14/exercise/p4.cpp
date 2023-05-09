/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p4.cpp
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#include "person.h"
#include <string>
#include <cstring>
#include <iostream>

const int SIZE = 5;

int main() {
    using namespace std;

    Person* lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++) {
        char choice;
        cout << "Enter the Person category:" << endl
            << "g:gunslinger   p:pokerplayer    "
            << "b:baddude    q:quit" << endl;
        cin >> choice;
        while (strchr("gpbq", choice) == NULL) {
            cout << "Please enter a g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q') {
            break;
        }
        switch (choice) {
            case 'g':
                lolas[ct] = new Gunslinger;
                break;
            case 'p':
                lolas[ct] = new PokerPlayer;
                break;
            case 'b':
                lolas[ct] = new BadDude;
                break;
            default:
                break;
        }
        cin.get();
        lolas[ct]->set();
    }

    cout << endl << "Here are all people:" << endl;
    int i;
    for (i = 0; i < ct; i++) {
        cout << endl;
        lolas[i]->show();
    }
    for (i = 0; i < ct; i++) {
        delete lolas[i];
    }
    cout << "Bye." << endl;

    return 0;
}