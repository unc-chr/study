/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：singleton.h
*   Author：leekaihua
*   Date：2024年03月27日
*   Brife：
*



*/
#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace lee {
    namespace utility {
        template <typename T>
        class Singleton {
            private:
                Singleton() {}
                Singleton(const Singleton<T>&) {};
                Singleton<T>& operator=(const Singleton<T>&) {};
                ~Singleton() {}
            private:
                static T* m_instance;
            public:
                static T* instance() {
                    if (m_instance == nullptr) {
                        return new T();
                    }
                    return m_instance;
                }
        };

        template <typename T>
        T* Singleton<T>::m_instance = nullptr;
    }
}

class TestSingleton {
    private:
        string m_name;
    public:
        TestSingleton() : m_name("TestSingleton") {};
        TestSingleton(string name) : m_name(name) {};
        ~TestSingleton() {}
    public:
        void show() const {
            cout << m_name << endl;
        }
};