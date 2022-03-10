#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

const char *	Bureaucrat::GradeTooHighException::what() const throw() {

	return "Grade is tow high! (valid grades range : 150 - 1)";
}

const char *	Bureaucrat::GradeTooLowException::what() const throw() {

	return "Grade is tow low! (valid grades range : 150 - 1)";
}

Bureaucrat::Bureaucrat() : _name ( "Default Bureaucrat" ), _grade ( 150 ) {

	return;
}

Bureaucrat::Bureaucrat(std::string const & name, unsigned int const grade) : _name ( name ) {

	if ( grade < 1 )
		throw( Bureaucrat::GradeTooHighException() );
	else if ( grade > 150 )
		throw( Bureaucrat::GradeTooLowException() );
	else
		this->_grade = grade;

	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name ( src._name ) {

	*this = src;

	return;
}

Bureaucrat::~Bureaucrat() {

	return;
}

const std::string &	Bureaucrat::getName() const {

	return this->_name;
}

unsigned int	Bureaucrat::getGrade() const {

	return this->_grade;	
}

void	Bureaucrat::incrementGrade() {

	if ( this->_grade == 1 )
		throw( Bureaucrat::GradeTooHighException() );

	this->_grade--;

	return;
}

void	Bureaucrat::decrementGrade() {

	if ( this->_grade == 150 )
		throw( Bureaucrat::GradeTooLowException() );

	this->_grade++;

	return;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs ) {

	if ( this != &rhs ) {

		this->_grade = rhs._grade;
	}

	return *this;
}

std::ostream	&	operator<<(std::ostream & os, Bureaucrat const & rhs) {

	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();

	return os;
}
