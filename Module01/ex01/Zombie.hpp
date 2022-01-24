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
	Zombie ( void );


	int		setName( std::string name );
	void	announce( void );

private:

	std::string	name;

};

Zombie*	zombieHorde( int N, std::string name );


#endif
