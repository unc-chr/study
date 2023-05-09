/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：move.cpp
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/
#include "move.h"
#include <iostream>

Move::Move(double a, double b) {
    x = a;
    y = b;
}

void Move::showmove() const {
    using std::cout;
    using std::endl;
    cout << "move x = " << x << " and b = " << y << endl;
}

Move Move::add(const Move& m) const {
    return Move(this->x + m.x, this->y + m.y);
}

void Move::reset(double a, double b) {
    this->x = a;
    this->y = b;
}