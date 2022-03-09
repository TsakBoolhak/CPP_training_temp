#include "Bureaucrat.hpp"
#include <iostream>

int	main() {

	Bureaucrat	Bob( "Bob", 150 );
	Bureaucrat	Bob2(Bob);
	Bureaucrat	John("John", 5);

	std::cout << John << std::endl;

	John = Bob;

	std::cout << Bob << std::endl;
	std::cout << Bob2 << std::endl;
	std::cout << John << std::endl;

	return 0;
}
