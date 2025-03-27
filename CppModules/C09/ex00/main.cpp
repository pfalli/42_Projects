#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Only input file: ./btc <...txt>" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange program(av[1]);
        // program.print_container();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}