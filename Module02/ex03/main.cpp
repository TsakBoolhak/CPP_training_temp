#include <iostream>
#include "Fixed.hpp"

int	main( void ) {

	Fixed	a(15);
	Fixed	b(15.25f);
//	Fixed	c(2);
	Fixed const c ( Fixed (34.56f) / Fixed (1.234f));

	std::cout << "a :" << a << std::endl;
	std::cout << "b :" << b << std::endl;
	std::cout << "c :" << c << std::endl;
	std::cout << "b - b :" << b - b << std::endl;
	std::cout << "b - a :" << b - a << std::endl;
	std::cout << "b + b :" << b + b << std::endl;
	std::cout << "b + a :" << b + a << std::endl;
	std::cout << "a * a :" << a * a << std::endl;
	std::cout << "b * b :" << b * b << std::endl;
	std::cout << "b / b :" << b / b << std::endl;
	std::cout << "a / c :" << a / c << std::endl;
	std::cout << "b / c :" << b / c << std::endl;

	return 0;
}
