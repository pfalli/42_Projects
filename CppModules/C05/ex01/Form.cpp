#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name(""), _signed(false), _gradeSign(0), _gradeExec(0) {
        
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Form::Form(const std::string name, int gradeSign)
    : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(0) {

    std::cout << "Name constructor called" << std::endl;
    if (gradeSign < 1)
        throw Form::GradeTooHighException();
    if (gradeSign > 150 )
        throw Form::GradeTooLowException();
}

Form::Form(const std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    std::cout << "Name constructor called" << std::endl;
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}



Form::Form(const Form &other) : _name(other._name), _signed(false), _gradeSign(other._gradeSign), _gradeExec(0) {
    std::cout << "Copy constructor called" << std::endl;
    return ;
}


Form &Form::operator=(const Form &other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        _signed = other._signed;
        // _name, _gradeSign, and _gradeExec are const and cannot be assigned
    }
    return (*this);
}


Form::~Form() {
    std::cout << "Default destructor called" << std::endl;
    return ;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form Name: " << form.getName() << ", Sign Grade: " << form.getGradeSign() << ", Execute Grade: " << form.getGradeExec() << ", is Signed: " << (form.getSigned() ? "true" : "false") << std::endl;
    return os;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

std::string Form::getName() const {
    return _name;
}

bool   Form::getSigned() const{
    return _signed;
}

int   Form::getGradeSign() const {
    return _gradeSign;
}

int   Form::getGradeExec() const {
    return _gradeExec;
}

void Form::beSigned( const Bureaucrat &bureaucrat) {
    if (_gradeSign < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    this->_signed = true;
    
}