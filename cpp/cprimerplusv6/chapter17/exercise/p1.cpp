/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2023年03月21日
*   Brife：
*



*/

#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter your string: ";
    char ch;
    int count;
    while(cin.get(ch)) {
        if (ch != '#') {
            count++;
        } else {
            cin.putback(ch);
            break;
        }
    }
    cout << "Your input " << count << " characters before #." << endl;

    char next_ch = cin.peek();
    cout << "Next char is: " << next_ch << endl;

    cout << "Done!" << endl;
    return 0;
}
