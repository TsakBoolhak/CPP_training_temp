#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {

public:

	Weapon( std::string initType );
	~Weapon ( void );
	
	void				setType( std::string newType );
	const std::string &	getType( void ) const;

private:	

	std::string	type;
	std::string &typeRef;

};

#endif
