/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：stack.cpp
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#include "stack.h"
Stack::Stack() {
    top = 0;
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
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return false;
    }
}