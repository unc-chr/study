/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_singleton.cpp
*   Author：leekaihua
*   Date：2024年03月27日
*   Brife：
*



*/
#include "singleton.h"
#include "test_singleton_good.h"

using namespace lee::utility;

int main() {
    Singleton<TestSingleton>::instance()->show();
    Singleton<TestSingletonGood>::instance()->show();
    return 0;
}
