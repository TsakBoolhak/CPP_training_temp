#include "iter.hpp"
#include <string>
#include <iostream>
#include <limits>

int	main( void ) {

	int		intArr[] = { 1, 3, 5, 7, std::numeric_limits<int>::max(), -10, std::numeric_limits<int>::min(), 10 };
	float	floatArr[] = { 1.2f, 3.5f, 5.9f, 7.65f, std::numeric_limits<float>::max(), -10.5f, std::numeric_limits<float>::min(), 10.f };
	std::string stringArr[] = { "one", "three", "five", "seven", "max", "minus ten", "min", "ten" };

	std::cout << sizeof(intArr) << std::endl;
	::iter( intArr, 8, ::printValue );
	std::cout << std::endl;
	::iter( floatArr, 8, ::printValue );
	std::cout << std::endl;
	::iter( stringArr, 8, ::printValue );
	return 0;
}
