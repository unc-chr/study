/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：usett0.cpp
*   Author：leekaihua
*   Date：2023年10月21日
*   Brife：
*



*/
#include <iostream>
#include "tabtenn0.h"

int main() {
    using std::cout;
    TableTennisPlayer player1("chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    player1.Name();
    if (player1.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }
    player2.Name();
    if (player2.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }

    return 0;
}