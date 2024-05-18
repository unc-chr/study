/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：stack.cpp
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#include <iostream>
#include "stack.h"
Stack::Stack() {
    top = 0;
    sum = 0;
}

bool Stack::isempty() const {
    return top == 0;
}

bool Stack::isfull() const {
    return top == MAX;
}

bool Stack::push(const Item& item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }
}

bool Stack::pop(Item& item) {
    using std::cout;
    using std::endl;

    if (top > 0) {
        item = items[--top];
        sum += item.payment;
        cout << "Now sum is " << sum << endl;        
        return true;
    } else {
        return false;
    }
}