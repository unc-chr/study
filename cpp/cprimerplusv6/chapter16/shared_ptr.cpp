/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：shared_ptr.cpp
*   Author：leekaihua
*   Date：2024年04月28日
*   Brife：
*



*/

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

void test() {
    int* p_int = new int(10);
    {
        std::shared_ptr<int> a(p_int);
        cout << a.use_count() << endl;
        {
            std::shared_ptr<int> b(p_int);
            cout << b.use_count() << endl;
        }
        cout << *p_int << endl;
    }
    cout << *p_int << endl;
    std::cout << "return" << std::endl;
    return;
}

int main() {
    test();
    return 0;
}