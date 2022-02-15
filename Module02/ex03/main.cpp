#include <iostream>
#include "Point.hpp"

int	main( void ) {

	Point	a;
	Point	b( 0.f, 1.f );
	Point	c ( 1.f, 0.f );
	Point	hypoMid(0.5f, 0.5f);
	Point	out(1.f, 1.f);
	Point	in(0.2f, 0.2f);

	if ( bsp( a, b, c, hypoMid ) )
		std::cout << "PROBLEM : hypoMid (which lies in the middle of the hypothenus of the triangle) should not be considered as inside the triangle" << std::endl;
	else
		std::cout << "hypoMid (which lies in the middle of the hypothenus of the triangle) is not considered as inside the triangle" << std::endl;

	if ( bsp( a, b, c, out ) )
		std::cout << "PROBLEM : out (which lies outside of the triangle) should not be considered as inside the triangle" << std::endl;
	else
		std::cout << "out is not inside the triangle" << std::endl;

	if ( bsp( a, b, c, in ) )
		std::cout << "in is inside the triangle" << std::endl;
	else
		std::cout << "PROBLEM : in (which lies inside of the triangle) should be considered as inside the triangle" << std::endl;

	if ( bsp( a, b, c, a ) )
		std::cout << "PROBLEM : a should not be considered as inside the triangle" << std::endl;
	else
		std::cout << "a is not considered as inside the triangle" << std::endl;

	if ( bsp( a, b, c, b ) )
		std::cout << "PROBLEM : b should not be considered as inside the triangle" << std::endl;
	else
		std::cout << "b is not considered as inside the triangle" << std::endl;

	if ( bsp( a, b, c, c ) )
		std::cout << "PROBLEM : c should not be considered as inside the triangle" << std::endl;
	else
		std::cout << "c is not considered as inside the triangle" << std::endl;

	return 0;
}
