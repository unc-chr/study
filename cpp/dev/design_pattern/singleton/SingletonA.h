/*================================================================
*   Copyright (C) 2024 Goldman Ltd. SingletonAll rights reserved.
*   
*   File：singleton.h
*   SingletonAuthor：leekaihua
*   Date：2024年03月27日
*   Brife：
*



*/
#pragma once

#include <iostream>
#include <string>

using namespace std;

class SingletonA {
    private:
        // 构造函数是私有的
        SingletonA() : m_name("SinigletonA") {}
        ~SingletonA() {}
        // 拷贝构造函数也是私有的
        SingletonA(const SingletonA&) {};
        // 赋值构造函数也是私有的
        SingletonA& operator=(const SingletonA&) {};

    private:
        // 私有的静态实例
        static SingletonA* m_instance;
        string m_name;

    public:
        static SingletonA* instance() {
            if (m_instance == nullptr) {
                m_instance = new SingletonA();
            }
            return m_instance;
        };

        void show() {
            cout << m_name << endl;
        }
};

SingletonA* SingletonA::m_instance = nullptr;