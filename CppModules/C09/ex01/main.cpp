#include "RPN.hpp"

int main() {
    std::string input;
    std::cout << "Enter RPN input: ";

    if (!std::getline(std::cin, input) || input.empty()) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }
    if (input == "random") {
        input = generateRandomRPN(10);
        std::cout << "Generated RPN: " << input << std::endl;
    }
    try {
        RPN program;
        program.calculator(input);
        std::cout << program.getResult() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
