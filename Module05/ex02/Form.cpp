#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

const char *	Form::GradeTooHighException::what() const throw() {

	return "Form's grade is tow high!";
}

const char *	Form::GradeTooLowException::what() const throw() {

	return "Form's grade is tow low!";
}

const char *	Form::FormNotSignedException::what() const throw() {

	return "Form is not signed!";
}

Form::Form() : _name ( "Default Form" ), _isSigned ( false ), _signingGrade ( 150 ), _executingGrade ( 150 ) {

	return;
}

Form::Form( std::string const & name, unsigned int const signingGrade, unsigned int const executingGrade ) : _name ( name ), _isSigned ( false ), _signingGrade ( signingGrade ), _executingGrade ( executingGrade ) {

	if ( signingGrade < 1 )
		throw( Form::GradeTooHighException() );
	else if ( signingGrade > 150 )
		throw( Form::GradeTooLowException() );

	if ( executingGrade < 1 )
		throw( Form::GradeTooHighException() );
	else if ( executingGrade > 150 )
		throw( Form::GradeTooLowException() );

	return;
}

Form::Form( Form const & src ) : _name ( src._name ), _isSigned ( false ), _signingGrade ( src._signingGrade ), _executingGrade ( src._executingGrade ) {

	return;
}

Form::~Form() {

	return;
}

const std::string &	Form::getName() const {

	return this->_name;
}

unsigned int	Form::getSigningGrade() const {

	return this->_signingGrade;
}

unsigned int	Form::getExecutingGrade() const {

	return this->_executingGrade;
}

bool	Form::getIsSigned() const {

	return this->_isSigned;
}

bool	Form::beSigned( Bureaucrat const & signingBureaucrat ) {

	if ( signingBureaucrat.getGrade() > this->_signingGrade )
		throw( Bureaucrat::GradeTooLowException() );

	if ( this->_isSigned == true )
		return false;

	this->_isSigned = true;

	return true;
}

void	Form::execute( Bureaucrat const & executor ) const {

	if ( this->getIsSigned() == false )
		throw ( Form::FormNotSignedException() );
	else if ( executor.getGrade() > this->_executingGrade )
		throw ( Bureaucrat::GradeTooLowException() );

	this->executeAction();

	return ;
}

Form &	Form::operator=( Form const & rhs ) {

	(void)(rhs);
	return *this;
}

std::ostream	&	operator<<( std::ostream & os, Form const & rhs ) {

	std::string isSigned;

	isSigned = rhs.getIsSigned() == true ? "signed" : "not signed";

	os << rhs.getName() << ", form which is " << isSigned << ", that has a signing grade of " << rhs.getSigningGrade() << " and an executing grade of " << rhs.getExecutingGrade();

	return os;
}
