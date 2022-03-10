#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main() {

	ShrubberyCreationForm	Shrub( "Bob" );
	RobotomyRequestForm		Robo( "Bob" );
	PresidentialPardonForm	Pres( "Bob" );
	Bureaucrat				Bill( "Bill", 1 );

	Bill.executeForm( Shrub );
	Bill.signForm( Shrub );
	Bill.executeForm( Shrub );

	Bill.executeForm( Robo );
	Bill.signForm( Robo );
	Bill.executeForm( Robo );

	Bill.executeForm( Pres );
	Bill.signForm( Pres );
	Bill.executeForm( Pres );

	return 0;
}
