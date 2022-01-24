////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//                              newZombie.cpp                                 //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Zombie.hpp"

Zombie*	newZombie( std::string name ) {

	Zombie	*zombie = new Zombie ( name );

	try {} catch (std::bad_alloc &ba) {

		std::cout << ba.what() << std::endl;

		return NULL;
	};
	
	return zombie;
}
