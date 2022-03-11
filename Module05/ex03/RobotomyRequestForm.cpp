#include <string>
#include <cstdlib>
#include <ctime>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : Form( "robotomy request", 72, 45 ), _target ( target ) {

	std::srand( std::time( NULL ) );

	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form( src.getName(), src.getSigningGrade(), src.getExecutingGrade() ), _target ( src._target ) {

	std::srand( std::time( NULL ) );
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm() {

	return ;
}

void	RobotomyRequestForm::executeAction() const {

	std::cout << "BLLBLLLBLBLBLBLBLBLBLBLBLBLBLBLBLBL (loud drilling noise)" << std::endl << this->_target;
	if ( rand() % 2 )
		std::cout << " has been robotomized !" << std::endl;
	else
		std::cout << " was strong enough to resist the robotomy !" << std::endl;

	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {

	(void)rhs;

	return *this;
}

RobotomyRequestForm::RobotomyRequestForm() : Form( "shrubbery creation", 72, 45 ), _target ( "Default target" ) {

	std::srand( std::time( NULL ) );

	return ;
}
