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
#include <fstream>
#include <cstdlib>

struct donater {
    char name[20];
    double donate_amount;
};

int main() {
    using std::cout;
    using std::endl;

    std::ifstream in_file;
    in_file.open("input_for_p9");
    if (!in_file.is_open()) {
        exit(EXIT_FAILURE);
    }

    int donate_num;
    in_file >> donate_num;
    in_file.get();

    donater * p_donater = new donater[donate_num];
    int counter = 0;
    int j = 0;
    while (in_file.good()) {
        if (counter % 2 == 0) {
            in_file.getline(p_donater[j].name, 20);
        } else {
            in_file >> p_donater[j].donate_amount;
            in_file.get();
            j++;
        }
        counter++;
    }

    if (in_file.eof()) {
        cout << "End of file reached." << endl;
    } else if (in_file.fail()) {
        cout << "input terminated by data mismatched" << endl;
    } else {
        cout << "input terminated for uknown reasons" << endl;
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

    in_file.close();
    delete [] p_donater;
    return 0;
}