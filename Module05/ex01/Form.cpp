#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

const char *	Form::GradeTooHighException::what() const throw() {

	return "Grade is tow high! (valid grades range : 150 - 1)";
}

const char *	Form::GradeTooLowException::what() const throw() {

	return "Grade is tow low! (valid grades range : 150 - 1)";
}

Form::Form() : _name ( "Default Form" ), _isSigned ( false ), _signingGrade ( 150 ), _executingGrade ( 150 ) {

	return;
}

Form::Form(std::string const & name, unsigned int const signingGrade, unsigned int const executingGrade) : _name ( name ), _isSigned ( false ) {

	if ( signingGrade < 1 )
		throw( Form::GradeTooHighException() );
	else if ( signingGrade > 150 )
		throw( Form::GradeTooLowException() );
	else
		this->_signingGrade = signingGrade;

	if ( executingGrade < 1 )
		throw( Form::GradeTooHighException() );
	else if ( executingGrade > 150 )
		throw( Form::GradeTooLowException() );
	else
		this->_executingGrade = executingGrade;

	return;
}

Form::Form( Form const & src ) : _name ( src._name ) {

	*this = src;

	return;
}

Form::~Form() {

	return;
}

const std::string &	Form::getName() const {

	return this->_name;
}

unsigned int	Form::getGrade() const {

	return this->_grade;	
}

Form &	Form::operator=( Form const & rhs ) {

	if ( this != &rhs ) {

		this->_grade = rhs._grade;
	}

	return *this;
}

std::ostream	&	operator<<(std::ostream & os, Form const & rhs) {

	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();

	return os;
}
