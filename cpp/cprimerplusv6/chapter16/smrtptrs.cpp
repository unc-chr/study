/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：smrtptrs.cpp
*   Author：leekaihua
*   Date：2023年03月22日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <memory>

class Report {
    private:
        std::string str;
    public:
        Report(const std::string s) : str(s) {
            std::cout << "Object created!" << std::endl;
        }
        ~Report() {
            std::cout << "Object deleted!" << std::endl << std::endl;
        }
        void comment() const {
            std::cout << str << std::endl;
        }
};

int main() {
    {
        std::auto_ptr<Report> ps (new Report("using auto_prt"));
        ps->comment();
    }
    {
        std::shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps (new Report("using unique_ptr"));
        ps->comment();
    }
    return 0;
}