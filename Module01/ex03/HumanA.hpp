#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA {

public:

	HumanA( std::string assignName, Weapon assignWeapon );
	~HumanA ( void );
	
	void	attack( void );

private:	

	std::string	name;
	Weapon		weapon;	

};

#endif
