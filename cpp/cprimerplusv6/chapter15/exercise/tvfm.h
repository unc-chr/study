/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：tvfm.h
*   Author：leekaihua
*   Date：2022年01月17日
*   Brife：
*



*/

#ifndef TVFM_H_
#define TVFM_H_

class Tv;
class Remote {
    public:
        enum State {Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        enum {NORMAL, INTERACT};
    private:
        int mode;
        int inter_mode;
    public:
        friend class Tv;
        Remote(int m = TV, int im = NORMAL) : mode(m), inter_mode(im) {}
        bool volup(Tv& t);
        bool voldown(Tv& t);
        void onoff(Tv& t);
        void chanup(Tv& t);
        void chandown(Tv& t);
        void set_mode(Tv& t);
        void set_input(Tv& t);
        void set_chan(Tv& t, int c);
        void show_mode() const;
        void switch_inter_mode(Tv& t) const;
};

class Tv {
    private:
        int state;
        int volume;
        int maxchannel;
        int channel;
        int mode;
        int input;
    public:
        friend class Remote;
        enum State {Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        enum {NORMAL, INTERACT};

        Tv(int s = Off, int mc = 125) : state(s), volume(5),
            maxchannel(mc), channel(2), mode(Cable), input(TV) {}
        void onoff() {state = (state == On) ? Off : On;}
        bool ison() const {return state == On;}
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode() {mode = (mode == Antenna) ? Cable : Antenna;}
        void set_input() {input = (input == TV) ? DVD : TV;}
        void settings() const;
        void switch_inter_mode(Remote& r) const;
        void show_mode() const;
};

inline bool Remote::volup(Tv& t) {return t.volup();}
inline bool Remote::voldown(Tv& t) {return t.voldown();}
inline void Remote::onoff(Tv& t) {t.onoff();}
inline void Remote::chanup(Tv& t) {t.chanup();}
inline void Remote::chandown(Tv& t) {t.chandown();}
inline void Remote::set_mode(Tv& t) {t.set_mode();}
inline void Remote::set_input(Tv& t) {t.set_input();}
inline void Remote::set_chan(Tv& t, int c) {t.channel = c;}

#endif