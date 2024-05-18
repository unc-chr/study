/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p8.cpp
*   Author：leekaihua
*   Date：2023年03月04日
*   Brife：
*



*/

#include <iostream>
#include <cstring>

int main() {
    using namespace std;

    cout << "Enter words (to stop, type the word done):" << endl;
    char word_input[30] = {};
    int count = 0;
    cin >> word_input;
    while (strcmp(word_input, "done")) {
        count++;
        cin >> word_input;
    }
    cout << "You entered a total of " << count << " words." << endl;

    return 0;
}