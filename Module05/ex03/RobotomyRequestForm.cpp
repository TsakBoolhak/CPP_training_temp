#include <string>
#include <cstdlib>
#include <ctime>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : Form( "robotomy request", 72, 45 ), _target ( target ) {

	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form( src.getName(), src.getSigningGrade(), src.getExecutingGrade() ), _target ( src._target ) {

	return ;
}

RobotomyRequestForm::~RobotomyRequestForm() {

	return ;
}

void	RobotomyRequestForm::executeAction() const {

	static bool	firstCall = true;

	if ( firstCall == true ) {

		std::srand( std::time( NULL ) );
		firstCall = false;
	}

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

	return ;
}
