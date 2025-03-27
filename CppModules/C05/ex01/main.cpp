#include "Bureaucrat.hpp"
#include "Form.hpp"

void form_exceptions(void)
{
    try
    {
        Form resign("resign", 0, 10);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
    try
    {
        Form resign("resign", 10, 0);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
        try
    {
        Form resign("resign", 151, 10);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
    try
    {
        Form resign("resign", 10, 151);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
}

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

        Form contract("contract", 14);
        std::cout << contract << std::endl;
        Piero.signForm(contract);
        std::cout << contract << std::endl;

        Form newContract("newContract", 10);
        std::cout << newContract << std::endl;
        Piero.signForm(newContract);
        std::cout << newContract << std::endl;
        
        std::cout << "***form expections" << std::endl;
        form_exceptions();
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }    

    return 0;
}