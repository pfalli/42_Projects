#include "ScalarConverter.hpp"

// more tests

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: input mistake: ./main [....]" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0; 
}