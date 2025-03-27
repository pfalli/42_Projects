#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    std::cout << "Name constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return ;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){
    std::cout << "Copy constructor called" << std::endl;
    return ;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    std::cout << "Assignment operator called" << std::endl;
    if ( this != &other )
        _grade = other.getGrade();
    return *this;
}


Bureaucrat::~Bureaucrat() {
    std::cout << "Default destructor called" << std::endl;
    return ;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat Name: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
    return os;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade(int n) {
    if (this->_grade - n < 1)
        throw GradeTooHighException();
    if (this->_grade - n > 150)
        throw GradeTooLowException();
    this->_grade = _grade - n;
    std::cout << "Increment Grade" << std::endl;
}

void Bureaucrat::decrementGrade(int n) {
    if (this->_grade + n < 1)
        throw GradeTooHighException();
    if (this->_grade + n > 150)
        throw GradeTooLowException();
    this->_grade = _grade + n;
    std::cout << "Decrement Grade" << std::endl;
}

void Bureaucrat::signAForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e){
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}