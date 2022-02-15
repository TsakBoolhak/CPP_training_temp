#include <iostream>
#include "Fixed.hpp"

int	main( void ) {

	std::cout << "--------SUBJECT'S MAIN--------" << std::endl << std::endl;
	{
		Fixed	a;
		Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << std::endl << "--------SUBJECT'S MAIN OVER--------" << std::endl << std::endl;

	{
		Fixed	a( 10 );
		Fixed	b( a );
		Fixed	c( 10.5f );
		Fixed	d ( a - b );
		Fixed	e ( c + a );
		Fixed	f ( a / 2);
		Fixed	g ( a * 2);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "e = " << e << std::endl;
		std::cout << "f = " << f << std::endl;
		std::cout << "g = " << g << std::endl << std::endl;

		if (a == b)
			std::cout << "a is equal b" << std::endl;
		if (a == c)
			std::cout << "PROBLEM : a was evaluated as equal c" << std::endl;

		if (a != c)
			std::cout << "a is not equal c" << std::endl;
		if (a != b)
			std::cout << "PROBLEM : a was evaluated as not equal b" << std::endl;

		if (a < c)
			std::cout << "a is lower than c" << std::endl;
		if (a < b)
			std::cout << "PROBLEM : a was evaluated as lower than b" << std::endl;

		if (a > f)
			std::cout << "a is greater than f" << std::endl;
		if (a > b)
			std::cout << "PROBLEM : a was evaluated as greater than b" << std::endl;

		if (a <= b)
			std::cout << "a is lower than or equal b" << std::endl;
		if (a <= f)
			std::cout << "PROBLEM : a was evaluated as lower than or equal f" << std::endl;
		if (a <= g)
			std::cout << "a is lower than or equal g" << std::endl;

		if (a >= b)
			std::cout << "a is greater than or equal b" << std::endl;
		if (a >= g)
			std::cout << "PROBLEM : a was evaluated as greater than or equal g" << std::endl;
		if (a >= g)
			std::cout << "a is greater than or equal f" << std::endl;
	}
	return 0;
}
