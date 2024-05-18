/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：stack.h
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack {
    private:
        enum {MAX = 10};
        Item items[MAX];
        int top;
    public:
        Stack();
        bool isempty() const;
        bool isfull() const;
        bool push(const Item& item);
        bool pop(Item& item);
};

#endif