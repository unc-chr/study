/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：stacker.cpp
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#include <iostream>
#include <cctype>
#include "stack.h"

int main() {
    using namespace std;
    Stack st;
    char ch;
    unsigned long po;

    cout << "Please enter A to add a purchase order,\n"
        << " p to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.isfull())
                    cout << "stack already full\n";
                else
                    st.push(po);
                break;
            case 'p':
            case 'P':
                if (st.isempty())
                    cout << "Stack already empty\n";
                else {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                }
                break;
            
            default:
                break;
        }
        cout << "Please enter A to add a purchase order,\n"
            << " P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";

    return 0;
}
