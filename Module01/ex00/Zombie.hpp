////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//                                Zombie.hpp                                  //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {

public:

	Zombie( std::string initName );
	~Zombie( void );



	void	announce( void );

private:

	Zombie ( void );
	std::string	name;

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );


#endif
