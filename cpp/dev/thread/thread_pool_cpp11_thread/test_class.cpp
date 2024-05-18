/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_class.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class Test {
    private:
        string m_str;
    public:
        Test(string str = "hello  world") : m_str(str) {}
        void print_public() {
            cout << "print_public" << endl;
            this->print();
        }
    public:
        static void print() {
            cout << "print" << endl;
            print2();
        }
        static void print2() {
            cout << "print2" << endl;
        }
};

int main() {
    Test t1 = Test();
    t1.print_public();
    Test::print();
    t1.print();
    return 0;
}