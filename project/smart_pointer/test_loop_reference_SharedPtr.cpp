/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_loop_reference.cpp
*   Author：leekaihua
*   Date：20240603
*   Brife：
*



*/
#include <iostream>
#include <string>

#include "shared_ptr.h"
#include "weak_ptr.h"

using lee::util::SharedPtr;

class Teacher;

class School {
    private:
        std::string name;
        SharedPtr<Teacher> principal;
    public:
        void set_principal(SharedPtr<Teacher> v_principal) {
            principal = v_principal;
        }
        ~School() {
            std::cout << "destroy" << std::endl;
        }
};

class Teacher {
    private:
        std::string name;
        int age;
        SharedPtr<School> school;
    public:
        void set_school(SharedPtr<School> v_school) {
            school = v_school;
        }
        ~Teacher() {
            std::cout << "destroy Teacher" << std::endl;
        }
};

int main() {
    {
        SharedPtr<Teacher> teacher_1(new Teacher());
        SharedPtr<School> school_1(new School());
        std::cout << teacher_1.use_count() << std::endl; // 1
        std::cout << school_1.use_count() << std::endl;  // 1
        teacher_1->set_school(school_1);
        school_1->set_principal(teacher_1);
        std::cout << teacher_1.use_count() << std::endl;  // 2
        std::cout << school_1.use_count() << std::endl;  // 2
    }
    return 0;
}