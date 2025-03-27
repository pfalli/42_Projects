#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; // circular dependency

class AForm {
	protected:
	    const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;

	public:
		AForm();
		AForm(const std::string name, int gradeSign, int gradeExec);
		AForm(const AForm& other);
        AForm &operator=(const AForm &other);
	    virtual ~AForm();

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(const Bureaucrat &bureaucrat);

		friend std::ostream &operator<<(std::ostream &os, const AForm &AForm);

		virtual void execute( const Bureaucrat& executor ) const = 0;

		

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
