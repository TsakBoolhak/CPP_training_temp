#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

const char *	Bureaucrat::GradeTooHighException::what() const throw() {

	return "Bureaucrat's grade is tow high!";
}

const char *	Bureaucrat::GradeTooLowException::what() const throw() {

	return "Bureaucrat's grade is tow low!";
}

Bureaucrat::Bureaucrat() : _name ( "Default Bureaucrat" ), _grade ( 150 ) {

	return;
}

Bureaucrat::Bureaucrat( std::string const & name, unsigned int const grade ) : _name ( name ) {

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

	if ( this->_grade <= 1 )
		throw( Bureaucrat::GradeTooHighException() );

	this->_grade--;

	return;
}

void	Bureaucrat::decrementGrade() {

	if ( this->_grade >= 150 )
		throw( Bureaucrat::GradeTooLowException() );

	this->_grade++;

	return;
}

void	Bureaucrat::signForm( Form & formToSign ) {

	bool check;

	std::cout << this->_name;
	try
	{
		check = formToSign.beSigned( *this );
	}
	catch ( std::exception & e ) {

		std::cout << " couldn't sign " << formToSign.getName() << " because " << e.what() << std::endl;

		return;
	}

	if ( check == false )
		std::cout << " couldn't sign " << formToSign.getName() << " because it was already signed." << std::endl;
	else
		std::cout << " signed " << formToSign.getName() << std::endl;

	return ;
}

void	Bureaucrat::executeForm( Form const & form ) {

	try {

		form.execute( *this );
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch ( std::exception & e ) {

		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	return ;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs ) {

	if ( this != &rhs ) {

		this->_grade = rhs._grade;
	}

	return *this;
}

std::ostream	&	operator<<( std::ostream & os, Bureaucrat const & rhs ) {

	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();

	return os;
}
