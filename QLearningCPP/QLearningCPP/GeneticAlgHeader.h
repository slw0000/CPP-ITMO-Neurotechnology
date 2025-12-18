//
//  GeneticAlgHeader.h
//  QLearningCPP
//
//  Created by Artem Golubev
//

#pragma once

#include "PolynomHeader.h"
#include "ComplexNumHeader.h"

#include <cassert>
#include <iostream>
#include <string>
#include <ranges>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>


class Carrier {
public:
    Carrier();
    Carrier(const std::vector<double>& gens) : gens_(gens) {}

    bool operator<(const Carrier& other) const ;

    Carrier newChild(const Carrier& otherParent) const;
    void mergeForNew(const Carrier& otherParent);
    const std::vector<double>& gens() const;

    std::optional<double> target() const;
    void setTarget(double);

private:
    static double newGen(double gen1, double gen2);

private:
    std::vector<double> gens_;
    std::optional<double> target_;
};

class Population {
public:
    using FitnessFunction = std::function<double(const Carrier&)>;

    Population(const size_t& size, const unsigned numberRandomCarriers);

    void evo(const FitnessFunction& fitFunc, const unsigned numberEpoch);
    const Carrier& bestCarrier() const;

private:
    void calcFit(const FitnessFunction& fitFunction);
    void crossingover();

private:
    size_t size_;
    unsigned numberRandomCarriers_;
    std::vector<Carrier> contain_;
};
