/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：workermi.cpp
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#include "workermi.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Worker::Data() const {
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get() {
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n') {
        continue;
    }
}

Worker::~Worker() {}

void Waiter::Data() const {
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get() {
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n') {
        continue;
    }
}

void Waiter::Set() {
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const {
    cout << "Category: waiter" << endl;
    Worker::Data();
    Data();
}

char* Singer::pv[Singer::Vtypes] = {"other", "alto",
    "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Data() const {
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get() {
    cout << "Enter number for singer's vocal range: " << endl;
    int i;
    for (i = 0; i < Vtypes; i++) {
        cout << i << ": " << pv[i] << " ";
        if (i % 4 == 3) {
            cout << endl;
        }
    }
    if (i % 4 != 0) {
        cout << endl;
    }
    cin >> voice;
    while (cin.get() != '\n') {
        continue;
    }
}

void Singer::Set() {
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const {
    cout << "Category: singer" << endl;
    Worker::Data();
    Data();
}

void SingingWaiter::Data() const {
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get() {
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set() {
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const {
    cout << "Category: singing waiter" << endl;
    Worker::Data();
    Data();
}