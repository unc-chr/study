/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：useless.cpp
*   Author：leekaihua
*   Date：2024年03月28日
*   Brife：
*   自己修改的文件，方便自己做实验。



*/
#include <iostream>
#include <utility>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Useless {
    private:
        // 对象的创建顺序
        int created_order;
        int n;
        char* p_char;
        string name;
    private:
        // 构造函数的调用次数，即对象的创建次数
        static int called_time;
        // 当前存在的对象总数
        static int instance_left;
    public:
        Useless();
        explicit Useless(int k, string v_name);
        Useless(int k, char ch, string v_name);
        Useless(const Useless& f);
        Useless(Useless& f);
        Useless(Useless&& f);
        Useless& operator=(const Useless& f);
        Useless& operator=(Useless& f);
        Useless& operator=(Useless&& f);
        ~Useless();
        Useless operator+(const Useless& f) const;
        void show_data() const;
        void show_object() const;
};

int Useless::called_time = 0;
int Useless::instance_left = 0;

Useless::Useless() {
    called_time++;
    instance_left++;
    created_order = called_time;
    n = 0;
    p_char = nullptr;
    name = "niming";
    cout << "default constructor called;" << endl;
    show_object();
}

Useless::Useless(int k, string v_name) : n(k), name(v_name) {
    called_time++;
    instance_left++;
    created_order = called_time;
    p_char = new char[n];
    for (int i = 0; i < n; i++) {
        p_char[i] = '_';
    }
    name = v_name;
    cout << "int constructor called; ";
    show_object();
}

Useless::Useless(int k, char ch, string v_name) : n(k), name(v_name) {
    called_time++;
    instance_left++;
    created_order = called_time;
    cout << "int, char constructor called;" << endl;
    p_char = new char[n];
    for (int i = 0; i < n; i++) {
        p_char[i] = ch;
    }
    name = v_name;
    show_object();
}

Useless::Useless(const Useless& f) : n(f.n) {
    called_time++;
    instance_left++;
    created_order = called_time;
    cout << "copy constructor called;" << endl;
    p_char = new char[n];
    for (int i = 0; i < n; i++) {
        p_char[i] = f.p_char[i];
    }
    name = f.name;
    show_object();
}

Useless::Useless(Useless& f) : n(f.n) {
    called_time++;
    instance_left++;
    created_order = called_time;
    cout << "left refer constructor called;" << endl;
    p_char = f.p_char;
    f.p_char = nullptr;
    f.n = 0;
    name = f.name;
    show_object();
}

Useless::Useless(Useless&& f) : n(f.n) {
    called_time++;
    instance_left++;
    created_order = called_time;
    cout << "right refer move constructor called;" << endl;
    p_char = f.p_char;
    f.p_char = nullptr;
    f.n = 0;
    name = f.name;
    show_object();
}

Useless& Useless::operator=(const Useless& f) {
    called_time++;
    created_order = called_time;
    cout << "copy assignment operator called: " << endl;
    if (this == &f) {
        return *this;
    }
    delete [] p_char;
    n = f.n;
    name = f.name;
    p_char = new char[n];
    for (int i = 0; i < n; i++) {
        p_char[i] = f.p_char[i];
    }
    return *this;
}

Useless& Useless::operator=(Useless& f) {
    cout << "left refer assignment operator called: " << endl;
    if (this == &f) {
        return *this;
    }
    delete [] p_char;
    n = f.n;
    p_char = f.p_char;
    f.n = 0;
    f.p_char = nullptr;
    name = f.name;
    return *this;
}

Useless& Useless::operator=(Useless&& f) {
    called_time++;
    created_order = called_time;
    cout << "right refer move assignment operator called: " << endl;
    if (this == &f) {
        return *this;
    }
    delete [] p_char;
    n = f.n;
    p_char = f.p_char;
    f.n = 0;
    f.p_char = nullptr;
    name = f.name;
    return *this;
}

Useless::~Useless() {
    cout << "destructor called: ";
    instance_left--;
    show_object();
    delete [] p_char;
}

Useless Useless::operator+(const Useless& f) const {
    cout << "Entering operator+()" << endl;
    Useless temp = Useless(n + f.n, name + "+" + f.name);
    for (int i =0; i < n; i++) {
        temp.p_char[i] = p_char[i];
    }
    for (int i = n; i < temp.n; i++) {
        temp.p_char[i] = f.p_char[i - n];
    }
    cout << "leaving operator+()" << endl;
    return temp;
}

void Useless::show_object() const {
    cout << "created order: " << created_order
        << ", instance num: " << instance_left
        << ", Data name: " << name
        << ", Data length: " << n
        << ", Data address: " << (void*) p_char << endl;
    show_data();
    cout << endl;
}

void Useless::show_data() const {
    if (n == 0) {
        cout << "object empty";
    } else {
        for (int i = 0; i < n; i++) {
            cout << p_char[i];
        }
    }
    cout << endl;
}

int main() {
    {
        cout << "object one: " << endl;
        Useless one(1, 'x', "one");
        cout << "now object one: " << endl;
        one.show_object();

        cout << "object two: ";
        Useless two = one + one;
        cout << "now object two: " << endl;
        two.show_object();

        cout << "object three, four: " << endl;
        Useless three, four;
        cout << "three = one" << endl;
        three = one;
        cout << "now object three:";
        three.show_object();
        cout << "and object one = ";
        one.show_object();

        cout << "four = one + two" << endl;
        four = one + two;
        cout << "now object four: " << endl;
        four.show_object();

        cout << "four = move(three)" << endl;
        four = std::move(three);
        cout << "now object four: " << endl;
        four.show_object();

        cout << "and object one = " << endl;
        one.show_object();

        cout << endl;
        cout << "five(one+three)" << endl;
        Useless five(one + three);
        cout << "now object five = ";
        five.show_data();
    }

    return 0;
}