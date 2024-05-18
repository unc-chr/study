/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：move.h
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/
#pragma once
class Move {
    private:
        double x;
        double y;
    public:
        Move(double a = 0, double b = 0);
        void showmove() const;
        Move add(const Move& m) const;
        void reset(double a = 0, double b = 0);
};