#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main() {

	ShrubberyCreationForm	Shrub1( "Target1" );
	RobotomyRequestForm		Robo1( "Target1" );
	PresidentialPardonForm	Pres1( "Target1" );

	ShrubberyCreationForm	Shrub2( "Target2" );
	RobotomyRequestForm		Robo2( "Target2" );
	PresidentialPardonForm	Pres2( "Target2" );

	ShrubberyCreationForm	Shrub3( "Target3" );
	RobotomyRequestForm		Robo3( "Target3" );
	PresidentialPardonForm	Pres3( "Target3" );

	ShrubberyCreationForm	Shrub4( "Target4" );
	RobotomyRequestForm		Robo4( "Target4" );
	PresidentialPardonForm	Pres4( "Target4" );

	ShrubberyCreationForm	Shrub5( "Target5" );
	RobotomyRequestForm		Robo5( "Target5" );
	PresidentialPardonForm	Pres5( "Target5" );

	ShrubberyCreationForm	Shrub6( "Target6" );
	RobotomyRequestForm		Robo6( "Target6" );
	PresidentialPardonForm	Pres6( "Target6" );

	ShrubberyCreationForm	Shrub7( "Target7" );
	RobotomyRequestForm		Robo7( "Target7" );
	PresidentialPardonForm	Pres7( "Target7" );

	std::cout << "-------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat				Bill( "Bill", 5 );

		std::cout << Bill << std::endl;
		std::cout << Shrub1 << std::endl;
		std::cout << Robo1 << std::endl;
		std::cout << Pres1 << std::endl;

		std::cout << std::endl;

		Bill.executeForm( Shrub1 );
		Bill.signForm( Shrub1 );
		Bill.executeForm( Shrub1 );

		std::cout << std::endl;

		Bill.executeForm( Robo1 );
		Bill.signForm( Robo1 );
		Bill.executeForm( Robo1 );

		std::cout << std::endl;

		Bill.executeForm( Pres1 );
		Bill.signForm( Pres1 );
		Bill.executeForm( Pres1 );
	}
	std::cout << "-------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "-------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat				Bill( "Bill", 25 );

		std::cout << Bill << std::endl;
		std::cout << Shrub2 << std::endl;
		std::cout << Robo2 << std::endl;
		std::cout << Pres2 << std::endl;

		std::cout << std::endl;

		Bill.executeForm( Shrub2 );
		Bill.signForm( Shrub2 );
		Bill.executeForm( Shrub2 );

		std::cout << std::endl;

		Bill.executeForm( Robo2 );
		Bill.signForm( Robo2 );
		Bill.executeForm( Robo2 );

		std::cout << std::endl;

		Bill.executeForm( Pres2 );
		Bill.signForm( Pres2 );
		Bill.executeForm( Pres2 );
	}
	std::cout << "-------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "-------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat				Bill( "Bill", 45 );

		std::cout << Bill << std::endl;
		std::cout << Shrub3 << std::endl;
		std::cout << Robo3 << std::endl;
		std::cout << Pres3 << std::endl;

		std::cout << std::endl;

		Bill.executeForm( Shrub3 );
		Bill.signForm( Shrub3 );
		Bill.executeForm( Shrub3 );

		std::cout << std::endl;

		Bill.executeForm( Robo3 );
		Bill.signForm( Robo3 );
		Bill.executeForm( Robo3 );

		std::cout << std::endl;

		Bill.executeForm( Pres3 );
		Bill.signForm( Pres3 );
		Bill.executeForm( Pres3 );
	}
	std::cout << "-------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "-------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat				Bill( "Bill", 72 );

		std::cout << Bill << std::endl;
		std::cout << Shrub4 << std::endl;
		std::cout << Robo4 << std::endl;
		std::cout << Pres4 << std::endl;

		std::cout << std::endl;

		Bill.executeForm( Shrub4 );
		Bill.signForm( Shrub4 );
		Bill.executeForm( Shrub4 );

		std::cout << std::endl;

		Bill.executeForm( Robo4 );
		Bill.signForm( Robo4 );
		Bill.executeForm( Robo4 );

		std::cout << std::endl;

		Bill.executeForm( Pres4 );
		Bill.signForm( Pres4 );
		Bill.executeForm( Pres4 );
	}
	std::cout << "-------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "-------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat				Bill( "Bill", 137 );

		std::cout << Bill << std::endl;
		std::cout << Shrub5 << std::endl;
		std::cout << Robo5 << std::endl;
		std::cout << Pres5 << std::endl;

		std::cout << std::endl;

		Bill.executeForm( Shrub5 );
		Bill.signForm( Shrub5 );
		Bill.executeForm( Shrub5 );

		std::cout << std::endl;

		Bill.executeForm( Robo5 );
		Bill.signForm( Robo5 );
		Bill.executeForm( Robo5 );

		std::cout << std::endl;

		Bill.executeForm( Pres5 );
		Bill.signForm( Pres5 );
		Bill.executeForm( Pres5 );
	}
	std::cout << "-------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "-------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat				Bill( "Bill", 145 );

		std::cout << Bill << std::endl;
		std::cout << Shrub6 << std::endl;
		std::cout << Robo6 << std::endl;
		std::cout << Pres6 << std::endl;

		std::cout << std::endl;

		Bill.executeForm( Shrub6 );
		Bill.signForm( Shrub6 );
		Bill.executeForm( Shrub6 );

		std::cout << std::endl;

		Bill.executeForm( Robo6 );
		Bill.signForm( Robo6 );
		Bill.executeForm( Robo6 );

		std::cout << std::endl;

		Bill.executeForm( Pres6 );
		Bill.signForm( Pres6 );
		Bill.executeForm( Pres6 );
	}
	std::cout << "-------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "-------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat				Bill( "Bill", 150 );

		std::cout << Bill << std::endl;
		std::cout << Shrub7 << std::endl;
		std::cout << Robo7 << std::endl;
		std::cout << Pres7 << std::endl;

		std::cout << std::endl;

		Bill.executeForm( Shrub7 );
		Bill.signForm( Shrub7 );
		Bill.executeForm( Shrub7 );

		std::cout << std::endl;

		Bill.executeForm( Robo7 );
		Bill.signForm( Robo7 );
		Bill.executeForm( Robo7 );

		std::cout << std::endl;

		Bill.executeForm( Pres7 );
		Bill.signForm( Pres7 );
		Bill.executeForm( Pres7 );
	}
	std::cout << "-------------------------------------------------------------------" << std::endl;

	return 0;
}
