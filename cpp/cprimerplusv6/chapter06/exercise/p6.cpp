/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p6.cpp
*   Author：leekaihua
*   Date：2023年03月05日
*   Brife：
*



*/
#include <iostream>
#include <string>

struct donater {
    std::string name;
    double donate_amount;
};

int main() {
    using std::cout;
    using std::endl;
    using std::cin;

    int donate_num;
    cout << "Please enter doanter number: ";
    cin >> donate_num;

    donater * p_donater = new donater[donate_num];
    for (int i = 0; i < donate_num; i++) {
        cout << "doanter #" << i << ":" << endl;
        cout << "Enter name: ";
        cin >> p_donater[i].name;
        cout << "Enter donate amount: ";
        cin >> p_donater[i].donate_amount;
    }

    // show Grand Patrons
    int count_grand_patrons = 0;
    cout << "------grand patrons------" << endl;
    for (int i = 0; i < donate_num; i++) {
        if (p_donater[i].donate_amount > 10000) {
            cout << p_donater[i].name << endl;
            count_grand_patrons++;
        }
    }
    if (count_grand_patrons == 0) {
        cout << "None" << endl;
    }

    // show other Patrons
    int count_other_patrons = 0;
    cout << "------other patrons------" << endl;
    for (int i = 0; i < donate_num; i++) {
        if (p_donater[i].donate_amount <= 10000) {
            cout << p_donater[i].name << endl;
            count_other_patrons++;
        }
    }
    if (count_other_patrons == 0) {
        cout << "None" << endl;
    }

    return 0;
}