//
//  main.cpp
//  QLearningCPP
//
//  Created by Artem Golubev
//

#include "ComplexNumHeader.h"
#include "PolynomHeader.h"
#include "GeneticAlgHeader.h"
#include <iostream>


namespace Tests
    {
        void complexNumber() {
            auto imaginary = ComplexNumber(0, 1);
            auto real = ComplexNumber(2, 0);
            assert(imaginary + real == ComplexNumber(2, 1));
            assert(real.pow(5) == ComplexNumber(32, 0));
            
            std::vector<double> num = {3, 4};
            auto compNum = ComplexNumber(num);
            assert(compNum.abs() == 5);
        }

        void polynom() {
            auto poly = Polynom({ {0, 10}, {0, 1} });
            assert(poly.at({ 0, 0 }) == ComplexNumber(0, 10));
            assert(poly.at({ 1, 0 }) == ComplexNumber(0, 11));

            auto poly2 = Polynom({ {24, 0}, {-50, 0}, {35, 0}, {-10, 0}, {1, 0} });
            constexpr auto epsilonZero = 1e-6;
            assert(poly2.at({ 1, 0 }).abs() < epsilonZero);
            assert(poly2.at({ 2, 0 }).abs() < epsilonZero);
            assert(poly2.at({ 3, 0 }).abs() < epsilonZero);
            assert(poly2.at({ 4, 0 }).abs() < epsilonZero);
        }

        void genAlg() {
            auto poly = Polynom({ {24, 0}, {-50, 0}, {35, 0}, {-10, 0}, {1, 0} });

            auto fitnessFunc = [&poly](const Carrier& c)
                {
                    return poly.at(ComplexNumber(c.gens())).abs();
                };

            auto population = Population(10, 4);
            population.evo(fitnessFunc, 100);
            assert(population.bestCarrier().target().value() < 1);
        }
    }


int main() {
    Tests::complexNumber();
    Tests::polynom();
    
    return 0;
}
