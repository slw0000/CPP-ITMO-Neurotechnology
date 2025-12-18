//
//  Polynom.cpp
//  QLearningCPP
//
//  Created by Artem Golubev
//

#include "PolynomHeader.h"

ComplexNumber Polynom::at(const ComplexNumber& x) const {
    ComplexNumber result(0, 0);  // аккумулятор
    int i = 0;
    for (const auto& coef : *this) {
        result = result + x.pow(i) * coef;
        ++i;
    }
    return result;
}
