/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_complex_number.cpp
*   Author：leekaihua
*   Date：20240701
*   Brife：
*



*/

#include "complex_number.h"

using lee::util::ComplexNumber;

int main() {
    ComplexNumber a;
    a.report();
    ComplexNumber b(1, 2);
    b.report();
    ComplexNumber c = a + b;
    c.report();
    ComplexNumber d = a + 10;
    d.report();
    ComplexNumber e = a - b;
    e.report();
    ComplexNumber f = a - 10;
    f.report();
    ComplexNumber g = a * b;
    g.report();
    ComplexNumber h = a * 10;
    h.report();
    ComplexNumber i = 20 * a;
    i.report();

    ComplexNumber aa(1, 3);
    ComplexNumber bb(2, 4);
    aa.report();
    ComplexNumber aa1 = aa++;
    aa1.report();
    aa.report();
    ComplexNumber aa2 = ++aa;
    aa2.report();
    aa.report();
    aa += bb;
    aa.report();

    ComplexNumber cc;
    std::cin >> cc;
    std::cout << cc << std::endl;

    return 0;
}