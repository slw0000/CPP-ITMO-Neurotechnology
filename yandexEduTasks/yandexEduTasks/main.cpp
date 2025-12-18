//
//  main.cpp
//  yandexEduTasks
//
//  Created by Artem Golubev on 20.11.2025.
//

#include <iostream>



class Carrier {
public:
    Carrier();
    
    Carrier newChild(const Carrier& otherParent);
    
private:
    std::vector<double> gens_;
    std::optional<double> target_;
};




class Population {
public:
    using FitnessFunction = std::function<double(const Carrier&)>;
    
    Population();
    
    void evo(const FitnessFunction& fitFunction);
    
private:
    size_t size;
    unsigned numberRandomCarriers_;
    std::vector<Carrier> contain_;
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
