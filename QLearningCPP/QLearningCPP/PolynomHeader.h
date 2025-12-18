//
//  PolynomHeader.h
//  QLearningCPP
//
//  Created by Artem Golubev
//

#pragma once

#include "ComplexNumHeader.h"

#include <ranges>
#include <algorithm>

using BasePolynom = std::vector<ComplexNumber>;
class Polynom : BasePolynom
{
public:
    Polynom(BasePolynom content) {
        *this = *static_cast<Polynom*>(&content);
    };

    ComplexNumber at(const ComplexNumber& x) const;
};

