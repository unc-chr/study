/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：person.h
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#pragma once
#include <string>

class Person {
    private:
        std::string first_name;
        std::string last_name;
    protected:
        void get();
        void data() const;
    public:
        Person() {}
        Person(const std::string& fn, const std::string& ln)
            : first_name(fn), last_name(ln) {};
        virtual ~Person() {}
        virtual void show() const;
        virtual void set();
};

class Gunslinger : virtual public Person {
    private:
        double draw_time;
        int num_nick;
    protected:
        void get();
        void data() const;
    public:
        Gunslinger() {};
        Gunslinger(const std::string& fn, const std::string& ln, double d_time, int nn)
            : Person(fn, ln), draw_time(d_time), num_nick(nn) {};
        Gunslinger(const Person& per, double d_time, int nn)
            : Person(per), draw_time(d_time), num_nick(nn) {};
        virtual ~Gunslinger() {}
        double draw() const;
        virtual void show() const;
        virtual void set();
};

class PokerPlayer : virtual public Person {
    protected:
        void get();
        void data() const;
    public:
        PokerPlayer() {}
        PokerPlayer(const std::string& fn, const std::string& ln) : Person(fn, ln) {};
        PokerPlayer(const Person& per) : Person(per) {};
        virtual ~PokerPlayer() {}
        int draw() const;
        virtual void show() const;
        virtual void set();
};

class BadDude : public Gunslinger, public PokerPlayer {
    protected:
        void get();
        void data() const;
    public:
        BadDude() {}
        BadDude(const std::string& fn, const std::string& ln, double d_time, int nn)
            : Person(fn, ln), Gunslinger(fn, ln, d_time, nn) {};
        BadDude(const Person& per, double d_time, int nn)
            : Person(per), Gunslinger(per, d_time, nn) {};
        virtual ~BadDude() {}
        double gdraw() const;
        int cdraw() const;
        void set();
        void show() const;
};