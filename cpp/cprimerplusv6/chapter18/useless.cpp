/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：useless.cpp
*   Author：leekaihua
*   Date：2024年03月28日
*   Brife：
*



*/
#include <iostream>

using std::cout;
using std::endl;

class Useless {
    private:
        int n;
        char* p_char;
    private:
        static int called_time;
    private:
        void show_object() const;
    public:
        Useless();
        explicit Useless(int k);
        Useless(int k, char ch);
        Useless(const Useless& f);
        Useless(Useless&& f);
        Useless& operator=(const Useless& f);
        Useless& operator=(Useless&& f);
        ~Useless();
        Useless operator+(const Useless& f) const;
        void show_data() const;
};

int Useless::called_time = 0;

Useless::Useless() {
    called_time++;
    n = 0;
    p_char = nullptr;
    cout << "default constructor called; number of objects: " << called_time << endl;
    show_object();
}

Useless::Useless(int k) : n(k) {
    called_time++;
    cout << "int constructor called; number of objects: " << called_time << endl;
    p_char = new char[n];
    show_object();
}

Useless::Useless(int k, char ch) : n(k) {
    called_time++;
    cout << "int, char constructor called; number of objects: " << called_time << endl;
    p_char = new char[n];
    for (int i = 0; i < n; i++) {
        p_char[i] = ch;
    }
    show_object();
}

Useless::Useless(const Useless& f) : n(f.n) {
    called_time++;
    cout << "copy const constructor called; number of objects: " << called_time << endl;
    p_char = new char[n];
    for (int i = 0; i < n; i++) {
        p_char[i] = f.p_char[i];
    }
    show_object();
}

Useless::Useless(Useless&& f) : n(f.n) {
    called_time++;
    cout << "move constructor called; number of objects: " << called_time << endl;
    p_char = f.p_char;
    f.p_char = nullptr;
    f.n = 0;
    show_object();
}

Useless& Useless::operator=(const Useless& f) {
    cout << "copy assignment operator called: " << endl;
    if (this == &f) {
        return *this;
    }
    delete [] p_char;
    n = f.n;
    p_char = new char[n];
    for (int i = 0; i < n; i++) {
        p_char[i] = f.p_char[i];
    }
    return *this;
}

Useless& Useless::operator=(Useless&& f) {
    cout << "move assignment operator called: " << endl;
    if (this == &f) {
        return *this;
    }
    delete [] p_char;
    n = f.n;
    p_char = f.p_char;
    f.n = 0;
    f.p_char = nullptr;
    return *this;
}

Useless::~Useless() {
    cout << "destructor called; objects left: " << --called_time << endl;
    cout << "deleted object:" << endl;
    show_object();
    delete [] p_char;
}

Useless Useless::operator+(const Useless& f) const {
    cout << "Entering operator+()" << endl;
    Useless temp = Useless(n + f.n);
    for (int i =0; i < n; i++) {
        temp.p_char[i] = p_char[i];
    }
    for (int i = n; i < temp.n; i++) {
        temp.p_char[i] = f.p_char[i - n];
    }
    cout << "temp object: " << endl;
    cout << "leaving operator+()" << endl;
    return temp;
}

void Useless::show_object() const {
    cout << "Number of elements: " << n;
    cout << ", Data address: " << (void*) p_char << endl;
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
        Useless one(10, 'x');
        Useless two = one;
        Useless three(20, 'o');
        Useless four(one + two);

        cout << "object one: ";
        one.show_data();
        cout << "object two: ";
        two.show_data();
        cout << "object three: ";
        three.show_data();
        cout << "object four: ";
        four.show_data();
    }

    return 0;
}
