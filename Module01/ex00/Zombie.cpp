////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//                                Zombie.cpp                                  //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string initName ) : name ( initName ) {
	
	return ;
}

Zombie::~Zombie( void ) {

	return ;
}



void	Zombie::announce( void ) {

	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;

	return ;
}




Zombie::Zombie( void ) : name ( "John \"Zombie\" Doe" ) {
	
	return ;
}
