/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：cpp42.cpp
*   Author：leekaihua
*   Date：2023年03月29日
*   Brife：
*



*/

#include <iostream>
using namespace std;

class Person {
    friend void showAge(const Person& p);
    

    public:
        Person(int age) {
            this->age = age;
        }

    private:
        int age;
};

void showAge(Person& p) {
    cout << p.age << endl;
}

int main() {

    Person p(10);
    showAge(p);

    return 0;
}