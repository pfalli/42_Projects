#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    return ;
}


RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : Form(target, 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm Target constructor called" << _target << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
    : Form(other), _target(other._target) {
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
    return ;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "RobotomyRequestForm Assignment operator called" << std::endl;
    if (this != &other) {
        _signed = other._signed;
        // _name, _gradeSign, and _gradeExec are const and cannot be assigned
    }
    return (*this);
}


RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    std::cout << ".....drillllll.....drilllllll........drillllll......" <<std::endl;
    if (executor.getGrade() > _gradeExec) {
        std::cout << "Robotomy failed! " << std::endl;
        throw Form::GradeTooLowException();
    }
    else
        std::cout << _target << " has been robotomized successfully 50% of the time. " << std::endl;
}