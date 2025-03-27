#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; // circular dependency

class Form {
	private:
	    const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;

	public:
		Form();
		Form(const std::string name, int gradeSign);
		Form(const std::string name, int gradeSign, int gradeExec);
		Form(const Form& other);
        Form &operator=(const Form &other);
	    ~Form();

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(const Bureaucrat &bureaucrat);

		friend std::ostream &operator<<(std::ostream &os, const Form &form);


	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {return "Grade is too high!";}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {return "Grade is too low!";}
	};
	
};

#endif
