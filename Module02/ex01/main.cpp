#include <iostream>
#include "Fixed.hpp"

int	main( void ) {

	Fixed	a(15);
	Fixed	b(15.25f);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;

	return 0;
}
