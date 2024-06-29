/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_dynamic_cast.cpp
*   Author：leekaihua
*   Date：20240629
*   Brife：
*



*/
#include <iostream>

class Base {
public:
    virtual void func() = 0;
};

class Derive1 : public Base {
public:
    void func() {
        std::cout << "call Derive1::func" << std::endl;
    }
};

class Derive2 : public Base {
public:
    void func() {
        std::cout << "call Derive2::func" << std::endl;
    }
    void new_func() {
        std::cout << "call Derive2::derive02func" << std::endl;
    }
};

class Derive3 : public Base {
public:
    void func() {
        std::cout << "call Derive3::func" << std::endl;
    }
};

void show_func(Base* p) {
    // dynamic_cast 会检查p指针是否指向的是一个 Derive2 类型的对象
    // 具体是通过指针p访问 RTTI 信息
    // 如果是，dynamic_cast 转换类型成功，返回 Derive2 对象的地址
    // 否则，返回 nullptr。
    // static_cast 在这里也能强转，但结果是 nullptr。
    Derive2* pd2 = static_cast<Derive2*>(p);
    if (pd2 != nullptr) {
        pd2->new_func();
    } else {
        p->func();  // dynamic binding
    }
}

int main() {
    Derive1 d1;
    Derive2 d2;
    Derive3 d3;
    show_func(&d1);
    show_func(&d2);
    show_func(&d3);
    return 0;
}