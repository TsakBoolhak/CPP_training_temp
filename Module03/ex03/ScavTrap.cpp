#include <iostream>
#include <limits>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("Default ScavTrap name") {

	std::cout << this->_name << " : Default ScavTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap( src._name ) {

	*this = src;

	std::cout << this->_name << " : Copy ScavTrap constructor called" << std::endl;

	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ){

	std::cout << this->_name << " : String ScavTrap constructor called" << std::endl;

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	return ;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << this->_name << " : Scavtrap destructor called" << std::endl;

	return ;
}

void	ScavTrap::attack( const std::string& target ) {

	std::cout << "SCAV ATTACK : ";
	std::cout << this->_name;

	if (this->_hitPoints == 0)
	std::cout << " is lying on the ground, uncouncious and is unable to attack " << target << "!" << std::endl;

	else if ( this->_energyPoints > 0) {

		this->_energyPoints--;
		std::cout << " attacks " << target << ", causing " << this->_attackDamage << " points of damage ! He now has " << this->_energyPoints << " energy points left!"<< std::endl;
	}

	else
		std::cout << " is too exhausted to attack " << target << " and just mumble under his breath..." << std::endl;

	return ;
}

void	ScavTrap::guardGate() {

	std::cout << this->_name;
	if (this->_hitPoints == 0)
		std::cout << " is attempting to activate Gatekeeper mode, but the protocol fails due to uncounciousness!" << std::endl;
	else
		std::cout << " activates Gatekeeper mode!" << std::endl;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs ) {

	if (this != &rhs) {

		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	return *this;
}
