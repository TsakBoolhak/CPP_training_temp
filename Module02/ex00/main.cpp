#include <iostream>
#include "Fixed.hpp"

int	main( void ) {

	std::cout << "--------SUBJECT'S MAIN--------" << std::endl << std::endl;
	{
		Fixed	a;
		Fixed	b( a );
		Fixed	c;

		c = b;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;

	}
	std::cout << std::endl;
	std::cout << "--------SUBJECT'S MAIN OVER--------" << std::endl;
	std::cout << std::endl;

	Fixed	a;
	Fixed	b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;

	a.setRawBits(10);
	Fixed	c ( a );
	b = a;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
