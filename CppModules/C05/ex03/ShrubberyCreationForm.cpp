#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form(target, 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm Target constructor called: " << _target << std::endl;
    return ;

}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
    : Form(other), _target( other._target ){
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    return ;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    std::cout << "ShrubberyCreationForm Assignment operator called" << std::endl;
    if (this != &other) {
        _signed = other._signed;
        // _name, _gradeSign, and _gradeExec are const and cannot be assigned
    }
    return (*this);
}


ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->_gradeExec)
        throw Form::GradeTooLowException();
    std::ofstream newfile("shrubbery.txt");
    if (!newfile) {
        std::cout << " Error: couldn't create the file!" << std::endl;
        return ;
    }
    newfile << "-----------------------" << std::endl;
    newfile << "        ( ~ )     " << std::endl;
    newfile << "     (~       ~)     " << std::endl;
    newfile << "    (~         ~)" << std::endl;
    newfile << "      ( ~    ~)" << std::endl;
    newfile << "         | |" << std::endl;
    newfile << "         | |" << std::endl;
    newfile << "         | |" << std::endl;
    newfile << "         | |" << std::endl;
    newfile << "        /   \\" << std::endl;
    newfile << " -------------------- " << std::endl;

    newfile.close();
    std::cout << _target << " shrubbery created." << std::endl;
}