#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern Default constructor called" << std::endl;
    return ;
}


Intern::Intern(const Intern &other) {
    std::cout << "Intern Copy constructor called" << std::endl;
    (void) other;
    return ;
}


Intern &Intern::operator=(const Intern &other) {
    std::cout << "Intern Assignment operator called" << std::endl;
    if (this == &other)
		return *this;
	return *this;
}


Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

Form* Intern::makeForm(std::string name, std::string target ) {
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    Form *forms[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            for (int j = 0; j < 3; j++) {
                if (j != i) {
                    std::cout << "Delete form allocation: " << formNames[j] << std::endl;
                    delete forms[j];
                }
        }
            return forms[i];
        }
    }

    std::cout << "Intern cannot create the form " << name << std::endl;
    return NULL;
}
