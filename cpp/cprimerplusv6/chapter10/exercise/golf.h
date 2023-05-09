/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：golf.h
*   Author：leekaihua
*   Date：2021年12月31日
*   Brife：
*



*/
#pragma once
class Golf {
    static const int Len = 40;
    private:
        char fullname[Len];
        int m_handicap;
    public:
        Golf(const char* fn, int hc);
        Golf();
        void handicap(int hc);
        void showgolf() const;
};
