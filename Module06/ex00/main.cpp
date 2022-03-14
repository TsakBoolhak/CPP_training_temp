#include "ScalType.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int	main(int ac, char **av) {

	if ( ac != 2) {

		std::cout << "Program takes 1 and only 1 argument" << std::endl << "Usage : ./convert string_to_convert" << std::endl;		
		return 0;
	}

	ScalType	conv( av[1] );

	conv.displayConversions();

	return 0;
}
