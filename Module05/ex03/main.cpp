#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main() {

	Intern shitBag;
	Bureaucrat	Bill( "Bill", 1 );
	Form *	form;

	std::cout << "-------------------------------------------" << std::endl;
	form = shitBag.makeForm( "presidential pardon", "Bill" );
	if ( form ) {
		Bill.signForm( *form );
		Bill.executeForm( *form );
		delete form;
	}
	std::cout << "-------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "-------------------------------------------" << std::endl;
	form = shitBag.makeForm( "shrubbery creation", "Bill" );
	if ( form ) {
		Bill.signForm( *form );
		Bill.executeForm( *form );
		delete form;
	}
	std::cout << "-------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "-------------------------------------------" << std::endl;
	form = shitBag.makeForm( "robotomy request", "Bill" );
	if ( form ) {
		Bill.signForm( *form );
		Bill.executeForm( *form );
		delete form;
	}
	std::cout << "-------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "-------------------------------------------" << std::endl;
	form = shitBag.makeForm( "fuck the hierarchy", "Bill" );
	if ( form ) {
		Bill.signForm( *form );
		Bill.executeForm( *form );
		delete form;
	}
	std::cout << "-------------------------------------------" << std::endl;

	return 0;
}
