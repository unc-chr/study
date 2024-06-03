/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_loop_reference.cpp
*   Author：leekaihua
*   Date：20240603
*   Brife：
*



*/
#include <memory>
#include <iostream>
#include <string>

class Teacher;

class School {
    private:
        std::string name;
        std::shared_ptr<Teacher> principal;
    public:
        void set_principal(std::shared_ptr<Teacher> v_principal) {
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
        std::shared_ptr<School> school;
    public:
        void set_school(std::shared_ptr<School> v_school) {
            school = v_school;
        }
        ~Teacher() {
            std::cout << "destroy Teacher" << std::endl;
        }
};

int main() {
    {
        std::shared_ptr<Teacher> teacher_1 = std::make_shared<Teacher>();
        std::shared_ptr<School> school_1 = std::make_shared<School>();
        std::cout << teacher_1.use_count() << std::endl; // 1
        std::cout << school_1.use_count() << std::endl;  // 1
        teacher_1->set_school(school_1);
        school_1->set_principal(teacher_1);
        std::cout << teacher_1.use_count() << std::endl;  // 2
        std::cout << school_1.use_count() << std::endl;  // 2
    }
    return 0;
}