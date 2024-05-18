/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：plorg.h
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/
#pragma once

class Plorg {
    private:
        char m_name[20];
        int m_CI;
    public:
        Plorg();
        Plorg(char* name);
        void reset(int ci);
        void report();
};