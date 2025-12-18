//
//  ComplexNumHeader.h
//  QLearningCPP
//
//  Created by Artem Golubev
//

#pragma once

#include <cassert>
#include <ranges>


class ComplexNumber {
    public:
        ComplexNumber(const std::vector<double>& v);
        ComplexNumber(double re = 0, double im = 0) : re_(re), im_(im) {}

        double re() const;
        double im() const;
        double abs() const;
        ComplexNumber pow(unsigned n) const;
        
        ComplexNumber operator*(const ComplexNumber& other) const;
        ComplexNumber operator+(const ComplexNumber& other) const;
        bool operator==(const ComplexNumber& other) const;

    private:
        double re_{};
        double im_{};
    };
