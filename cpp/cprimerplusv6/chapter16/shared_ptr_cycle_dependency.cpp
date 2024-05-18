/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：shared_ptr_cycle_dependency.cpp
*   Author：leekaihua
*   Date：2024年04月28日
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
        std::weak_ptr<School> school;
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
        std::cout << teacher_1.use_count() << std::endl;
        std::cout << school_1.use_count() << std::endl;
        teacher_1->set_school(school_1);
        school_1->set_principal(teacher_1);
        std::cout << teacher_1.use_count() << std::endl;
        std::cout << school_1.use_count() << std::endl;
    }
    std::shared_ptr<Teacher> teacher_1 = std::make_shared<Teacher>();
    std::shared_ptr<School> school_1 = std::make_shared<School>();
    teacher_1->set_school(school_1);
    school_1->set_principal(teacher_1);
    std::cout << sizeof(teacher_1) << std::endl;

    return 0;
}