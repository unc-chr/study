/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_default_constructor.cpp
*   Author：leekaihua
*   Date：20240602
*   Brife：
*       测试默认构造函数的使用
*/

#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Person {
public:
    // 默认构造函数版本1
    // Person() {}
    // 默认构造函数版本2，和版本1本质一致
    // Person() = default;
    // 默认构造函数版本3，和版本1本质一致
    // Person() {
    //     name_ = "lee";
    //     age_ = 24;
    // }
    // 默认构造函数版本4，和版本1本质一致
    Person() : name_("lee"), age_(24) {}
    // 默认构造函数版本5，提供默认初始值
    // Person(string name = "lee", int age = 24) {}
    // 默认构造函数版本6，和版本5本质一致
    // Person(string name, int age) : name_("lee"), age_(24) {}

    Person(string name, int age) : name_(name), age_(age) {}
    // 构造函数，和上面的构造函数一致
    // Person(string name, int age) {
    //     name_ = name;
    //     age_ = age;
    // }

    ~Person() = default;

    void show() {
        cout << "My name is " << name_
                << ", and I am " << age_
                << " years old. " << endl;
    }

private:
    string name_;
    int age_;
};


int main() {

    std::unique_ptr<Person> p1 = std::make_unique<Person>();
    p1->show();
    std::unique_ptr<Person> p2 = std::make_unique<Person>("lili", 25);
    p2->show();
    return 0;
}