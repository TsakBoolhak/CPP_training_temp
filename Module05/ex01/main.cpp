#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main() {

	Bureaucrat	beginner( "Beginner", 150 );
	Bureaucrat	intermediate( "Intermediate", 75 );
	Bureaucrat	pro( "Pro", 1 );

	std::cout << beginner << std::endl;
	std::cout << intermediate << std::endl;
	std::cout << pro << std::endl;

	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------------------" << std::endl;
	{
		Form		noobForm( "Noob Form", 150, 150 );
		Form		midForm( "Mid Form", 75, 75 );
		Form		proForm( "Pro Form", 1, 1 );

		std::cout << noobForm << std::endl;
		std::cout << midForm << std::endl;
		std::cout << proForm << std::endl;

		std::cout << std::endl;

		beginner.signForm( noobForm );
		beginner.signForm( midForm );
		beginner.signForm( proForm );
		beginner.signForm( noobForm );

		std::cout << std::endl;

		std::cout << noobForm << std::endl;
		std::cout << midForm << std::endl;
		std::cout << proForm << std::endl;
	}

	std::cout << "----------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------------------" << std::endl;
	{
		Form		noobForm( "Noob Form", 150, 150 );
		Form		midForm( "Mid Form", 75, 75 );
		Form		proForm( "Pro Form", 1, 1 );

		std::cout << noobForm << std::endl;
		std::cout << midForm << std::endl;
		std::cout << proForm << std::endl;

		std::cout << std::endl;

		intermediate.signForm( noobForm );
		intermediate.signForm( midForm );
		intermediate.signForm( proForm );
		intermediate.signForm( noobForm );

		std::cout << std::endl;

		std::cout << noobForm << std::endl;
		std::cout << midForm << std::endl;
		std::cout << proForm << std::endl;
	}

	std::cout << "----------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------------------" << std::endl;
	{
		Form		noobForm( "Noob Form", 150, 150 );
		Form		midForm( "Mid Form", 75, 75 );
		Form		proForm( "Pro Form", 1, 1 );

		std::cout << noobForm << std::endl;
		std::cout << midForm << std::endl;
		std::cout << proForm << std::endl;

		std::cout << std::endl;

		pro.signForm( noobForm );
		pro.signForm( midForm );
		pro.signForm( proForm );
		pro.signForm( noobForm );

		std::cout << std::endl;

		std::cout << noobForm << std::endl;
		std::cout << midForm << std::endl;
		std::cout << proForm << std::endl;
	}

	std::cout << "----------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::cout << "now let's try to create a form with a signing grade too high" << std::endl;
	try {

		Form	Error("lol", 0, 150);
	}
	catch ( std::exception & e) {

		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "now let's try to create a form with an executing grade too high" << std::endl;
	try {

		Form	Error("lol", 150, 0);
	}
	catch ( std::exception & e) {

		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "now let's try to create a form with a signing grade too low" << std::endl;
	try {

		Form	Error("lol", 151, 150);
	}
	catch ( std::exception & e) {

		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "now let's try to create a form with an executing grade too low" << std::endl;
	try {

		Form	Error("lol", 150, 151);
	}
	catch ( std::exception & e) {

		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
