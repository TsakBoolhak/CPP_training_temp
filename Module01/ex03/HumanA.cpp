#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( std::string assignName, Weapon assignWeapon ) : name ( assignName ), weapon ( assignWeapon ) {
	
	return ;
};

HumanA::~HumanA( void ) {
	
	return ;
}

void	HumanA::attack (void ) {

	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;

	return ;
}
