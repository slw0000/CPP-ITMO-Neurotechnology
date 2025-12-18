//
//  ComplexNum.cpp
//  QLearningCPP
//
//  Created by Artem Golubev
//

#include "ComplexNumHeader.h"

using namespace std;



ComplexNumber::ComplexNumber(const std::vector<double>& v) :
        re_(v[0]), im_(v[1]) {}

double ComplexNumber::re() const {
    return re_;
}

double ComplexNumber::im() const {
    return im_;
}

double ComplexNumber::abs() const {
    return sqrt(im_ * im_ + re_ * re_);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    return {
        re_ * other.re() - im_ * other.im(),
        re_ * other.im() + other.re() * im_
    };
}

ComplexNumber ComplexNumber::pow(unsigned n) const {
    if (n == 0)
        return {1, 0};
    if (n == 1)
        return { re_, im_ };
    return *this * pow(n - 1);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return { re_ + other.re(), im_ + other.im() };
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {
    return re_ == other.re() && im_ == other.im_;
}
