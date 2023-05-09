/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p6.cpp
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/
#include "move.h"
#include <iostream>

int main() {
    using namespace std;
    Move move1;
    move1.showmove();

    Move move2(3, 4);
    move2.showmove();

    Move move3(2, 8);
    move3.showmove();

    Move move4 = move2.add(move3);
    move4.showmove();

    move3.reset(1, 1);
    move3.showmove();

    return 0;
}