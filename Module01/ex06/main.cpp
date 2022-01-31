#include "Karen.hpp"
#include <iostream>
#include <string>

int	main(int ac, char **av) {

	Karen karen;
	const std::string level[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int	index = 0;

	if (ac == 2)
	{
		while (index < 4) {
			if (level[index].compare(av[1]) == 0)
				break;
			index++;
		}
		if (index == 4)
			karen.complain( av[1] );
		else {
			while ( index < 4 ) {
				karen.complain( level[index] );
				index++;
			}
		}
	}
	else
		std::cout << "Wrong number of arguments" << std::endl << "Usage exemple : KarenFilter \"WARNING\"" << std::endl;

	return 0;
}
