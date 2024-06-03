/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_smart_ptr.cpp
*   Author：leekaihua
*   Date：20240602
*   Brife：
*



*/
#include <iostream>
#include <string>

#include "auto_ptr.h"
#include "smart_ptr.h"
#include "shared_ptr.h"
#include "unique_ptr.h"

using namespace lee::util;

class Test {
public:
    Test() = default;
    Test(const std::string& name) : name_(name) {
        std::cout << "Test is created." << std::endl;
    }
    ~Test() {
        std::cout << "Test is deleted." << std::endl;
    }

    void set_name(std::string& name) {
        name_ = name;
    }
    std::string& name() {
        return name_;
    }
private:
    std::string name_;
};

int main() {
    SmartPtr<Test> sp1(new Test("li"));
    std::cout << sp1->name() << std::endl;

    AutoPtr<Test> ap(new Test("lee"));
    std::cout << ap->name() << std::endl;
    // AutoPtr<Test> ap2 = ap;
    AutoPtr<Test> ap2(ap);
    std::cout << ap2->name() << std::endl;

    UniquePtr<Test> up1(new Test("jack"));
    std::cout << up1->name() << std::endl;
    // 拷贝构造被禁用，所以编译阶段会报错。
    // UniquePtr<Test> up2(up1);
    // 赋值构造被禁用，所以编译阶段会报错。
    // UniquePtr<Test> up2 = up1;
    UniquePtr<Test> up2(std::move(up1));
    std::cout << up2->name() << std::endl;

    SharedPtr<Test> shp1(new Test("shared_ptr"));
    std::cout << shp1->name() << std::endl;
    std::cout << shp1.use_count() << std::endl;
    SharedPtr<Test> shp2 = shp1;
    std::cout << shp1.use_count() << std::endl;
    std::cout << shp2.use_count() << std::endl;

    return 0;
}
