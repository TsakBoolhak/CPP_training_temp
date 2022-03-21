#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int	main() {

	int	myArray[] = { 1, 3, 10, -3, 33, 42, 101010 };

	std::vector<int> myVector(myArray, myArray + sizeof( myArray ) / sizeof( int ));
	std::list<int> myList(myArray, myArray + sizeof( myArray ) / sizeof( int ));
	std::deque<int> myDeque(myArray, myArray + sizeof( myArray ) / sizeof( int ));
	
	std::cout << "myVector :" << std::endl;
	for (std::vector<int>::iterator it = myVector.begin() ; it != myVector.end() ; ++it ) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myList :" << std::endl;
	for (std::list<int>::iterator it = myList.begin() ; it != myList.end() ; ++it ) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myDeque :" << std::endl;
	for (std::deque<int>::iterator it = myDeque.begin() ; it != myDeque.end() ; ++it ) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	for ( int i = -5 ; i < 5 ; i++)
	{
		std::vector<int>::iterator vectorIt = ::easyfind(myVector, i);
		std::list<int>::iterator listIt = ::easyfind(myList, i);
		std::deque<int>::iterator dequeIt = ::easyfind(myDeque, i);
		std::cout << i << " was ";
		if ( vectorIt == myVector.end() )
			std::cout << "not ";
		std::cout << "found in myVector" << std::endl;
		std::cout << i << " was ";
		if ( listIt == myList.end() )
			std::cout << "not ";
		std::cout << "found in myList" << std::endl;
		std::cout << i << " was ";
		if ( dequeIt == myDeque.end() )
			std::cout << "not ";
		std::cout << "found in myDeque" << std::endl;
		std::cout << std::endl;
	}


	return 0;
}
