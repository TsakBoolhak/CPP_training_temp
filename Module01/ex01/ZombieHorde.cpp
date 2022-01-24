////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//                             zombieHorde.cpp                                //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {

	Zombie	*zombies = new Zombie[N];

	try {} catch (std::bad_alloc &ba) {

		std::cout << ba.what() << std::endl;

		return NULL;
	};

	for (int i = 0; i < N ; i++)
		zombies[i].setName( name );

	return zombies;
}
