#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat Piero("Piero", 12);
        std::cout << Piero << std::endl;
        Piero.incrementGrade(5);
        std::cout << Piero << std::endl;
        Piero.decrementGrade(100);
        std::cout << Piero << std::endl;
        Piero.decrementGrade(100);
        std::cout << Piero << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat President("President", 151);
        std::cout << President << std::endl;
        President.incrementGrade(20);
        std::cout << President << std::endl;

    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    

    return 0;
}