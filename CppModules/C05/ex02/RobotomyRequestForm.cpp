#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
    std::cout << "Default constructor called" << std::endl;
    return ;
}


RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm(target, 72, 45), _target(target) {
    std::cout << "Target constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
    : AForm(other), _target(other._target) {
    std::cout << "Copy constructor called" << std::endl;
    return ;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        _signed = other._signed;
        // _name, _gradeSign, and _gradeExec are const and cannot be assigned
    }
    return (*this);
}


RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Default destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    std::cout << ".....drillllll.....drilllllll........drillllll......" <<std::endl;
    if (executor.getGrade() > _gradeExec) {
        throw AForm::GradeTooLowException();
        std::cout << "Robotomy failed! " << std::endl;
    }
    else
        std::cout << _target << " has been robotomized successfully 50% of the time. " << std::endl;
}