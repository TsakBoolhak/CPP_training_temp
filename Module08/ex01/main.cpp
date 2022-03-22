#include "Span.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

int	main() {

	std::cout << "----------SUBJECT'S MAIN----------" << std::endl;
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "----------FURTHER  TESTS----------" << std::endl << std::endl;
	std::cout << "----ADDING NUMBER ON EMPTY SPAN---" << std::endl;
	{
		Span	sp = Span();

		try {

			sp.addNumber(1);
		} catch ( std::exception const & e ) {

			std::cout << "Exception raised : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "----LONGEST SPAN ON EMPTY SPAN----" << std::endl;
	{
		Span	sp = Span();

		try {

			sp.longestSpan();
		} catch ( std::exception const & e ) {

			std::cout << "Exception raised : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "----SHORTEST SPAN ON EMPTY SPAN---" << std::endl;
	{
		Span	sp = Span();

		try {

			sp.shortestSpan();
		} catch ( std::exception const & e ) {

			std::cout << "Exception raised : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--LONGEST SPAN ON ONE VALUE SPAN--" << std::endl;
	{
		Span	sp = Span(1);

		sp.addNumber(1);
		try {

			sp.longestSpan();
		} catch ( std::exception const & e ) {

			std::cout << "Exception raised : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--SHORTEST SPAN ON ONE VALUE SPAN-" << std::endl;
	{
		Span	sp = Span(1);

		sp.addNumber(1);
		try {

			sp.shortestSpan();
		} catch ( std::exception const & e ) {

			std::cout << "Exception raised : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "----ADDING NUMBER ON FULL SPAN----" << std::endl;
	{
		Span	sp = Span(1);

		sp.addNumber(1);
		try {

			sp.addNumber(2);
		} catch ( std::exception const & e ) {

			std::cout << "Exception raised : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "----SPAN FILLED WITH SAME VALUE---" << std::endl;
	{
		Span	sp = Span(10);

		for ( int i = 0 ; i < 10 ; ++i )
			sp.addNumber(1);

		std::cout << "longest span : " << sp.longestSpan() << std::endl;
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl << "--SPAN FILLED INCREMENTED VALUES--" << std::endl;
	{
		Span	sp = Span(10);

		for ( int i = 0 ; i < 10 ; ++i )
			sp.addNumber(i);

		std::cout << "longest span : " << sp.longestSpan() << std::endl;
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl << "-ONLY CONTAIN INT_MIN AND INT_MAX-" << std::endl;
	{
		Span	sp = Span(10);

		sp.addNumber( std::numeric_limits<int>::min() );
		sp.addNumber( std::numeric_limits<int>::max() );

		std::cout << "longest span : " << sp.longestSpan() << std::endl;
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl << "-ADD SEQUENCE FROM A SHORT VECTOR-" << std::endl;
	{
		Span	sp = Span(5);
		int	myArray[] = { -42, std::numeric_limits<int>::max(), 3, 101010, std::numeric_limits<int>::min() };
		std::vector<int>	myVector( myArray, myArray + sizeof( myArray ) / sizeof( *myArray ) );

		sp.insertSequence( myVector.begin(), myVector.end() );
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl << "--ADD SEQUENCE TOO LARGE TO FIT---" << std::endl;
	{
		Span	sp = Span(4);
		int	myArray[] = { -42, std::numeric_limits<int>::max(), 3, 101010, std::numeric_limits<int>::min() };
		std::vector<int>	myVector( myArray, myArray + sizeof( myArray ) / sizeof( *myArray ) );

		try {

			sp.insertSequence( myVector.begin(), myVector.end() );
			std::cout << "longest span : " << sp.longestSpan() << std::endl;
			std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
		} catch ( std::exception const & e ) {

			std::cout << "Exception raised : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "-ADD NUMBER AFTER ADDING SEQUENCE THAT JUST FIT-" << std::endl;
	{
		Span	sp = Span(5);
		int	myArray[] = { -42, std::numeric_limits<int>::max(), 3, 101010, std::numeric_limits<int>::min() };
		std::vector<int>	myVector( myArray, myArray + sizeof( myArray ) / sizeof( *myArray ) );

		sp.insertSequence( myVector.begin(), myVector.end() );
		try {
			sp.addNumber(0);
			std::cout << "longest span : " << sp.longestSpan() << std::endl;
			std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
		} catch ( std::exception const & e ) {

			std::cout << "Exception raised : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "-ADD SEQUENCE FROM A LARGE VECTOR-" << std::endl;
	{
		const	unsigned int VALUES_NB = 1000000;
		Span	sp = Span(VALUES_NB);
		std::vector<int>	myVector( VALUES_NB, 0);
		srand(time(NULL));
		int	count = 0;
		int	min = std::numeric_limits<int>::max(),	max = std::numeric_limits<int>::min();

		for ( std::vector<int>::iterator it = myVector.begin() ; it != myVector.end() ; ++it ) {

			int value = rand() - std::numeric_limits<int>::min();
			int	sign = rand() % 2;
			if ( sign ) {
				count++;
				value = (value + 1) * -1;
			}
			if ( value < min )
				min = value;
			if (value > max )
				max = value;
			*it = value;
		}

		std::cout << count << " positive values (or zero) and " << VALUES_NB - count << " negative values" << std::endl;
		sp.insertSequence( myVector.begin(), myVector.end() );
		std::cout << "lowest random value : " << min << "    highest random value : " << max << std::endl;
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	}

	return 0;
}
