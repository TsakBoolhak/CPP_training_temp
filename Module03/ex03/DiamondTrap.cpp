#include <iostream>
#include <limits>
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap ("default DiamondTrap_clap_name"), ScavTrap("default DiamondTrap"), FragTrap("default DiamondTrap"), _name ("default DiamondTrap") {

	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) {

	std::cout << "Copy DiamondTrap constructor called" << std::endl;

	*this = src;

	return ;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name" ), ScavTrap(name), FragTrap(name), _name (name){

	std::cout << "String DiamondTrap constructor called" << std::endl;

	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	return ;
}

DiamondTrap::~DiamondTrap( void ) {

	std::cout << "Diamondtrap destructor called" << std::endl;

	return ;
}

void	DiamondTrap::attack( const std::string& target ) {

	ScavTrap::attack(target);

	return ;
}

void	DiamondTrap::whoAmI( void ) {

	std::cout << "my name : " << this->_name << " my claptrap's name : " << this->ClapTrap::_name << std::endl;
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & rhs ) {

	if (this != &rhs) {

		this->_name = rhs._name;
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	return *this;
}
