/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：workmi.cpp
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#include "workermi.h"
#include "queuetp.h"
#include <string>
#include <cstring>
#include <iostream>

const int SIZE = 5;

int main() {
    using namespace std;

    QueueTp<Worker*> q_workers(SIZE);

    int ct;
    Worker* temp;
    for (ct = 0; ct < SIZE; ct++) {
        char choice;
        cout << "Enter the employee category:" << endl
            << "w:waiter    s:singer   "
            << "t:singing waiter    q:quit" << endl;
        cin >> choice;
        while (strchr("wstq", choice) == NULL) {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        cin.get();
        if (choice == 'q') {
            break;
        }
        switch (choice) {
            case 'w':
                temp = new Waiter;
                temp->Set();
                q_workers.enqueue(temp);
                break;
            case 's':
                temp = new Singer;
                temp->Set();
                q_workers.enqueue(temp);
                break;
            case 't':
                temp = new SingingWaiter;
                temp->Set();
                q_workers.enqueue(temp);
                break;
            default:
                break;
        }
    }

    cout << endl << "Here is your staff:" << endl;
    Worker* out;
    while (!q_workers.isempty()) {
        q_workers.dequeue(out);
        out->Show();
        cout << endl;
    }

    cout << "Bye." << endl;

    return 0;
}