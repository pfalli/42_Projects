#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// void AForm_exceptions(void)
// {
//     try
//     {
//         AForm resign("resign", 0, 10);
//     }
//     catch (std::exception &err){
//         std::cerr << err.what() << std::endl;
//     }
//     try
//     {
//         AForm resign("resign", 10, 0);
//     }
//     catch (std::exception &err){
//         std::cerr << err.what() << std::endl;
//     }
//         try
//     {
//         AForm resign("resign", 151, 10);
//     }
//     catch (std::exception &err){
//         std::cerr << err.what() << std::endl;
//     }
//     try
//     {
//         AForm resign("resign", 10, 151);
//     }
//     catch (std::exception &err){
//         std::cerr << err.what() << std::endl;
//     }
// }

/* AForm is an Abstract Class, so i cannot instantiate directly a class, but trhough a Derived Class Form */
int main() {
    try {
        Bureaucrat Piero("Piero", 12);
        std::cout << Piero << std::endl;

        // Bureaucrat Jack(Piero);
        // std::cout << Jack << std::endl;

        // Bureaucrat Tody("Tody", 66);
        // std::cout << Tody << std::endl;
        // Jack = Tody;
        // std::cout << Jack << std::endl;

        PresidentialPardonForm form1("President");
        ShrubberyCreationForm form2("Shrubber");
        RobotomyRequestForm form3("Robot");
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
        Piero.signAForm(form1);
        Piero.signAForm(form2);
        Piero.signAForm(form3);
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
        Piero.executeForm(form1);
        Piero.executeForm(form2);
        Piero.executeForm(form3);
        
        // std::cout << "***AForm expections" << std::endl;
        // AForm_exceptions();
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }    

    return 0;
}