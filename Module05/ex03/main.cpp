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

	form = shitBag.makeForm("presidential pardon", "Bill");
	if ( form ) {
		Bill.signForm(*form);
		Bill.executeForm(*form);
		delete form;
	}

	form = shitBag.makeForm("shrubbery creation", "Bill");
	if ( form ) {
		Bill.signForm(*form);
		Bill.executeForm(*form);
		delete form;
	}

	form = shitBag.makeForm("robotomy request", "Bill");
	if ( form ) {
		Bill.signForm(*form);
		Bill.executeForm(*form);
		delete form;
	}

	form = shitBag.makeForm("fuck the hierarchy", "Bill");
	if ( form ) {
		Bill.signForm(*form);
		Bill.executeForm(*form);
		delete form;
	}

	return 0;
}
