#include <string>
#include <iostream>

int	main (void) {

	std::string	str ("HI THIS IS BRAIN");
	std::string *strPTR = &str;
	std::string	&strREF = str;

	std::cout << "The memory address of the str variable is " << &str <<std::endl;
	std::cout << "The memory address held by strPTR is " << strPTR << std::endl;
	std::cout << "The memory address held by strREF is " << &strREF << std::endl;


	std::cout << "The value of the str variable is " << str << std::endl;
	std::cout << "The value pointed to by strPTR is " << *strPTR << std::endl;
	std::cout << "The value pointed to by strREF is " << strREF << std::endl;

	return 0;
}
