/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_any.cpp
*   Author：leekaihua
*   Date：20240610
*   Brife：
        test any.
        this test code file is from cppreference.com
*/

#include "any.h"
#include <iostream>
#include <string>

class Person {
public:
    Person(std::string name = "lee", int age = 20)
            : name_(name)
            , age_(age) {}
    ~Person() = default;
    friend std::ostream& operator<<(std::ostream& os, const Person& target) {
        os << "person: " << target.name_
                << ", age: " << target.age_;
        return os;
    }
private:
    std::string name_;
    int age_;
};

int main() {
    Any a = Any(5);
    std::cout << a.any_cast<int>() << std::endl;
    a = Any(3.14);
    std::cout << a.any_cast<double>() << std::endl;
    a = Any(Person());
    std::cout << a.any_cast<Person>() << std::endl;
    return 0;
}