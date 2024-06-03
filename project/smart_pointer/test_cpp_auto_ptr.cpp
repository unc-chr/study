/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_cpp_auto_ptr.cpp
*   Author：leekaihua
*   Date：20240603
*   Brife：
*       测试标准库的 auto_ptr 指针



*/

#include <iostream>
#include <memory>

using namespace std;

int main() {
    {
        auto_ptr<int> ap1 = auto_ptr<int>(new int(1));
        auto_ptr<int> ap2 = ap1;
        // 下面一行将会报错，此时 ap1 拥有的指针已经是 0
        // gdb 调试可以验证这一点
        // cout << *ap1 << endl;
        cout << *ap2 << endl;
    }

    return 0;
}
