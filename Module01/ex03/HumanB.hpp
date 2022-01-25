#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB {

public:

	HumanB( std::string assignName );
	~HumanB ( void );
	
	void	attack( void );
	void	setWeapon (Weapon newWeapon);

private:	

	std::string	name;
	Weapon		*weapon;	

};

#endif
