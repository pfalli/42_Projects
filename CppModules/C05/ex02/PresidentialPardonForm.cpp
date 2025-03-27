#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    std::cout << "Default constructor called" << std::endl;
}

// PresidentialPardonForm::PresidentialPardonForm()
//     : AForm( "", 0, 0) {

//     std::cout << "Default constructor called" << std::endl;
// }

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm( target, 25, 5), _target( target ) {
    std::cout << "Target constructor called: " << getName() <<  std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
    : AForm(other), _target( other._target ) {
    std::cout << "Copy constructor called" << std::endl;
    return ;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        _signed = other._signed;
        // _name, _gradeSign, and _gradeExec are const and cannot be assigned
    }
    return (*this);
}


PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Default destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() < this->_gradeExec)
        throw AForm::GradeTooLowException();
    else
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
