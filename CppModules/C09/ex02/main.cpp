#include "PmergeMe.hpp"

int main (int ac, char **av) {
    if (ac < 2) {
        std::cout << "Error: insert input ./PmergeMe <...>\n";
        return 1;
    }
    try {
        PmergeMe program(av);
        program.printResult(av);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;

}