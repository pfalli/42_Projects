#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
    : _name(""), _signed(false), _gradeSign(0), _gradeExec(0) {
        
    std::cout << "Default constructor called" << std::endl;
    return ;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec)
    : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {

    std::cout << "Name constructor called" << std::endl;
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}



AForm::AForm(const AForm &other)
    : _name(other._name), _signed(false), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {

    std::cout << "Copy constructor called" << std::endl;
    return ;
}


AForm &AForm::operator=(const AForm &other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        _signed = other._signed;
        // _name, _gradeSign, and _gradeExec are const and cannot be assigned
    }
    return (*this);
}


AForm::~AForm() {
    std::cout << "Virtual destructor called" << std::endl;
    return ;
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
    os << "AForm Name: " << AForm.getName() << ", Sign Grade: " << AForm.getGradeSign() << ", Execute Grade: " << AForm.getGradeExec() << ", is Signed: " << (AForm.getSigned() ? "true" : "false") << std::endl;
    return os;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

std::string AForm::getName() const {
    return _name;
}

bool   AForm::getSigned() const{
    return _signed;
}

int   AForm::getGradeSign() const {
    return _gradeSign;
}

int   AForm::getGradeExec() const {
    return _gradeExec;
}

void AForm::beSigned( const Bureaucrat &bureaucrat) {
    if (_gradeSign < bureaucrat.getGrade())
        throw AForm::GradeTooLowException();
    this->_signed = true;
    
}
