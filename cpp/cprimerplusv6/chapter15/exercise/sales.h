/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：sales.h
*   Author：leekaihua
*   Date：2023年03月15日
*   Brife：
*



*/
#pragma once

#include <stdexcept>
#include <string>

class Sales {
    public:
        class bad_index : public std::logic_error {
            private:
                int bi;
            public:
                explicit bad_index (
                    int ix,
                    const std::string& s = "Index error in Sales objects\n");
                int bi_val() const {return bi;}
                virtual ~bad_index() throw() {}
        };

        enum {MONTHS = 12};
        explicit Sales(int yy = 0);
        Sales(int yy, const double* gr, int n);
        virtual ~Sales() {}
        int Year() const {return year;}
        virtual double operator[](int i) const;
        virtual double& operator[](int i);
    private:
        double gross[MONTHS];
        int year;
};

class LabeledSales : public Sales {
    private:
        std::string label;
    public:
        class nbad_index : public bad_index {
            private:
                std::string lbl;
            public:
                nbad_index(
                    const std::string& lb, int ix,
                    const std::string& s = "Index error in LabeledSales object\n");
                const std::string& label_val() const {return lbl;}
                virtual ~nbad_index() throw() {}
        };

        explicit LabeledSales(const std::string& lb = "none", int yy = 0);
        LabeledSales(const std::string& lb, int yy, const double* gr, int n);
        virtual ~LabeledSales() {}
        const std::string& Label() const {return label;}
        virtual double operator[](int i) const;
        virtual double& operator[](int i);
};