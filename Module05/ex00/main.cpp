#include "Bureaucrat.hpp"
#include <iostream>

int	main() {

	Bureaucrat	Bob( "Bob", 150 );
	Bureaucrat	Bob2( Bob );
	Bureaucrat	John( "John", 5 );

	std::cout << John << std::endl;

	std::cout << std::endl;

	John = Bob;

	std::cout << Bob << std::endl;
	std::cout << Bob2 << std::endl;
	std::cout << John << std::endl;

	std::cout << std::endl;

	try {

		std::cout << Bob << std::endl;
		std::cout << "Let's try to decrement Bob" << std::endl;
		Bob.decrementGrade();
	}
	catch ( std::exception & e ) {

		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Let's increment Bob until it fails" << std::endl;
	try {
		for ( size_t i = 0 ; i < 500 ; i++ ) {


			std::cout << Bob2 << std::endl;
			Bob2.incrementGrade();
		}
	}
	catch ( std::exception & e ) {

		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Let's decrement Bob until it fails" << std::endl;
	try {
		for ( size_t i = 0 ; i < 500 ; i++ ) {


			std::cout << Bob2 << std::endl;
			Bob2.decrementGrade();
		}
	}
	catch ( std::exception & e ) {

		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Let's try to create a Bureaucrat with a grade too high (0)" << std::endl;
	try {

		Bureaucrat	Joe( "Joe", 0 );
	}
	catch ( std::exception & e ) {

		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Let's try to create a Bureaucrat with a grade too low (0)" << std::endl;
	try {

		Bureaucrat	Bill( "Bill", 151 );
	}
	catch ( std::exception & e ) {

		std::cout << e.what() << std::endl;
	}

	return 0;
}
