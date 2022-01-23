#include <iostream>
#include <string>
#include <locale>

std::string	stringToUppercase( std::string str, std::locale loc )
{

	for (std::string::iterator it = str.begin() ; it != str.end() ; it++)
	{

		if (std::islower(*it, loc))
			*it = std::toupper(*it, loc);
	}

	return str;
}

int			main( int ac, char **av )
{

	std::locale loc;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	else {

		for (int i = 1; i < ac; i++) {

			std::string arg = av[i];
			std::cout << stringToUppercase( arg, loc );
		}
	}

	std::cout << std::endl;

	return 0;
}
