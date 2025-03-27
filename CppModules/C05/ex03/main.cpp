#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int main() {
    try {
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        if (rrf) {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }    

    return 0;
}

// int main() {
//     Form* robot = NULL; // i need to declare them outside the TRY in order to delete them inside CATCH;
//     Form* tree = NULL;
//     Form* president = NULL;
//     try {
//         Bureaucrat Piero("Piero", 46); //26, 46
//         Intern someRandomIntern;
//         robot = someRandomIntern.makeForm("robotomy request", "Bender");
//         tree = someRandomIntern.makeForm("shrubbery creation", "Tree");
//         president = someRandomIntern.makeForm("presidential pardon", "Douglas Adams");

//         std::cout << *robot << std::endl;
//         std::cout << *tree << std::endl;
//         std::cout << *president << std::endl;

//         robot->beSigned(Piero);
//         robot->execute(Piero);
//         std::cout << *robot << std::endl;

//         tree->beSigned(Piero);
//         tree->execute(Piero);
//         std::cout << *tree << std::endl;

//         president->beSigned(Piero);
//         president->execute(Piero);
//         std::cout << *president << std::endl;
        
//         delete robot;
//         delete tree;
//         delete president;

//     }
//     catch (const std::exception &e) {
//         std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
//         delete robot;
//         delete tree;
//         delete president;
//     }    

//     return 0;
// }