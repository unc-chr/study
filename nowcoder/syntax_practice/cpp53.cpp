/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：cpp53.cpp
*   Author：leekaihua
*   Date：2023年03月30日
*   Brife：
*



*/
#include <iostream>
// write your code here......
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Employee {

    private:
        string name;
        double salary;
    // write your code here......
    public:
        Employee(string name, double salary) {
            this->name = name;
            this->salary = salary;
        }
        double get_salary() const {
            return salary;
        }
        string get_name() {
            return name;
        }
        double cal_tax() const {
            double pre_tax = salary - 3500;
            double tax = 0;
            if (pre_tax > 80000) {
                tax = pre_tax * 0.45 - 13505;
            } else if (pre_tax > 55000) {
                tax = pre_tax * 0.35 - 5505;
            } else if (pre_tax > 35000) {
                tax = pre_tax * 0.30 - 2755;
            } else if (pre_tax > 9000) {
                tax = pre_tax * 0.25 - 1005;
            } else if (pre_tax > 4500) {
                tax = pre_tax * 0.2 - 555;
            } else if (pre_tax > 1500) {
                tax = pre_tax * 0.1 - 105;
            } else {
                tax = pre_tax * 0.03;
            }
            return tax;
        }
    

};

bool cmp(const Employee& a, const Employee& b) {
    return a.get_salary() > b.get_salary();
}

int main() {

    // write your code here......
    vector<Employee> emps;
    emps.push_back(Employee("张三", 6500));
    emps.push_back(Employee("李四", 8000));
    emps.push_back(Employee("王五", 100000));
    sort(emps.begin(), emps.end(), cmp);
    cout << fixed;
    for (auto iter = emps.begin(); iter != emps.end(); iter++) {
        cout << iter->get_name() << "应该缴纳的个人所得税是:" << setprecision(1) << iter->cal_tax() << endl;
    }

    return 0;
}
