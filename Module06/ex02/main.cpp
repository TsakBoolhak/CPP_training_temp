#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

typedef enum e_realType { TYPE_A, TYPE_B, TYPE_C, TYPE_UNKNOWN }t_realType;

Base *	generate() {

	static bool firstCall = true;

	if ( firstCall == true ) {

		srand( time( NULL ) );
		firstCall= false;
	}
	
	int	random = rand() % 3;

	switch ( random ) {

		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}

	return NULL;
}

void	identify( Base * p ) {

	std::cout << "Identifying real type through a pointer..."<< std::endl;
	std::cout << "Identified as : ";
	
	for ( int realType = TYPE_A ; realType < TYPE_UNKNOWN ; realType++ )
	{
		switch ( realType ) {

			case TYPE_A:
			{
				A *	typeA = dynamic_cast<A *>( p );
				if ( typeA != NULL ) {
					std::cout << "A" << std::endl;
					return ;
				}
				break;
			}
			case TYPE_B:
			{
				B *	typeB = dynamic_cast<B *>( p );
				if ( typeB != NULL ) {
					std::cout << "B" << std::endl;
					return ;
				}
				break;
			}
			case TYPE_C:
			{
				C *	typeC = dynamic_cast<C *>( p );
				if ( typeC != NULL ) {
					std::cout << "C" << std::endl;
					return ;
				}
				break;
			}
		}
	}
	std::cout << "unknown" << std::endl;
	return ;
}

void	identify( Base & p ) {

	std::cout << "Identifying real type through reference..."<< std::endl;
	std::cout << "Identified as : ";
	
	for ( int realType = TYPE_A ; realType < TYPE_UNKNOWN ; realType++ )
	{
		switch ( realType ) {

			case TYPE_A:
				try {

					A &	typeA = dynamic_cast<A &>( p );
					std::cout << "A" << std::endl;

					(void)typeA;
					return ;
				}
				catch (const  std::exception& e ) {}
				break;

			case TYPE_B:
				try {

					B &	typeB = dynamic_cast<B &>( p );
					std::cout << "B" << std::endl;
					(void)typeB;

					return ;
				}
				catch (const  std::exception& e ) {}
				break;

			case TYPE_C:
				try {

					C &	typeC = dynamic_cast<C &>( p );
					std::cout << "C" << std::endl;
					(void)typeC;

					return ;
				}
				catch (const  std::exception& e ) {}
				break;
		}
	}
	std::cout << "unknown" << std::endl;
	return ;
}

int	main() {


	for ( int i = 0 ; i < 10 ; i++ ) {
		Base * randomBasePtr = generate();
		Base & randomBaseRef = *randomBasePtr;
		
		identify( randomBasePtr );
		identify( randomBaseRef );
		std::cout << std::endl;

		delete randomBasePtr;
	}

	return 0;
}
