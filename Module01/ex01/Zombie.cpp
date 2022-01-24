////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//                                Zombie.cpp                                  //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string initName ) : name ( initName ) {
	
	return ;
}

Zombie::Zombie( void ) : name ( "John \"Zombie\" Doe" ) {
	
	return ;
}

Zombie::~Zombie( void ) {

	return ;
}






void	Zombie::announce( void ) {

	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;

	return ;
}

int		Zombie::setName( std::string name ) {

	if (name.empty())
		return EXIT_FAILURE;

	Zombie::name = name;

	return EXIT_SUCCESS;
}
