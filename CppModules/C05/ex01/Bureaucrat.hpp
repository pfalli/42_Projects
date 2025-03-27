#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class GradeTooHighException : public std::exception {
public:
	virtual const char* what() const throw() {return "Grade is too high!";}
};

class GradeTooLowException : public std::exception {
public:
	virtual const char* what() const throw() {return "Grade is too low!";}
};

// class GradeTooHighException : public std::exception {
// 	private:
// 	    std::string _message;

// 	public:
// 	    GradeTooHighException(const std::string& name) {
// 	        _message = "Grade is too high for " + name;
// 	    }

// 		virtual ~GradeTooHighException() throw() {
// 			std::cout << "Destructor Exception called" << std::endl;
// 		}

// 	    const char* what() const throw() {
// 	        return _message.c_str();
// 	    }
// 	};

// 	class GradeTooLowException : public std::exception {
// 	private:
// 	    std::string _message;

// 	public:
// 	    GradeTooLowException(const std::string& name) {
// 	        _message = "Grade is too low for " + name;
// 	    }

// 		virtual ~GradeTooLowException() throw() {
// 			std::cout << "Destructor Exception called" << std::endl;
// 		}

// 	    const char* what() const throw() {
// 	        return _message.c_str();
// 	    }
// 	};

class Form;

class Bureaucrat {
	private:
	    const std::string _name;
		int _grade;

	public:
	    Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
	    ~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade(int n);
		void decrementGrade(int n);

		void signForm(Form &form);

		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
	
};

#endif
