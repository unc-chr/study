/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_single_good.h
*   Author：leekaihua
*   Date：2024年03月27日
*   Brife：
*



*/
#pragma once

#include "singleton.h"

using namespace lee::utility;

class TestSingletonGood {
    friend class Singleton<TestSingletonGood>;
    private:
        string m_name;
    private:
        TestSingletonGood() : m_name("TestSingletonGood") {};
        TestSingletonGood(string name) : m_name(name) {};
        ~TestSingletonGood() {}
    public:
        void show() const {
            cout << m_name << endl;
        }
};