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
Stack::Stack(int n) {
    size = n;
    top = 0;
    pitems = new Item[size];
}

Stack::Stack(const Stack& st) {
    pitems = new Item[st.size];
    for (int i = 0; i < st.top; i++) {
        pitems[i] = st.pitems[i];
    }
    size = st.size;
    top = st.top;
}

Stack::~Stack() {
    delete []  pitems;
}

bool Stack::isempty() const {
    return top == 0;
}

bool Stack::isfull() const {
    return top == size;
}

bool Stack::push(const Item& item) {
    if (top < size) {
        pitems[top++] = item;
        return true;
    } else {
        return false;
    }
}

bool Stack::pop(Item& item) {
    if (top > 0) {
        item = pitems[--top];
        return true;
    } else {
        return false;
    }
}

Stack& Stack::operator=(const Stack& st) {
    if (this == &st) {
        return *this;
    }
    delete pitems;
    pitems = new Item[st.size];
    for (int i = 0; i < st.top; i++) {
        pitems[i] = st.pitems[i];
    }
    size = st.size;
    top = st.top;

    return *this;
}