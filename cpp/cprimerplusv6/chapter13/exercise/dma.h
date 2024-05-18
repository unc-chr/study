/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：dma.h
*   Author：leekaihua
*   Date：2022年01月08日
*   Brife：
*



*/

#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class DMA {
    private:
        char* label;
        int rating;
    public:
        DMA(const char* l = "null", int r = 0);
        DMA(const DMA& d);
        virtual ~DMA();
        DMA& operator=(const DMA& d);
        virtual void view() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const DMA& d);
};

class baseDMA : public DMA {
    public:
        baseDMA(const char* l = "null", int r = 0);
        baseDMA(const baseDMA& rs);
        virtual ~baseDMA();
        baseDMA& operator=(const baseDMA& rs);
        virtual void view() const;
        friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

class lacksDMA : public DMA {
    private:
        enum {COL_LEN = 40};
        char color[COL_LEN];
    public:
        lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
        lacksDMA(const char* c, const DMA& rs);
        virtual ~lacksDMA();
        virtual void view() const;
        friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};

class hasDMA : public DMA {
    private:
        char * style;
    public:
        hasDMA(const char* s = "none", const char* l = "null", int r = 0);
        hasDMA(const char* s, const DMA& rs);
        hasDMA(const hasDMA& hs);
        virtual ~hasDMA();
        virtual void view() const;
        hasDMA& operator=(const hasDMA& rs);
        friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};

#endif