#include <iostream>
#include <limits>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("Default FragTrap name") {

	std::cout << this->_name << " : Default FragTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	return ;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap( src._name ) {

	*this = src;

	std::cout << this->_name << " : Copy FragTrap constructor called" << std::endl;

	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ){

	std::cout << this->_name << " : String FragTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	return ;
}

FragTrap::~FragTrap( void ) {

	std::cout << this->_name << " : Fragtrap destructor called" << std::endl;

	return ;
}

void	FragTrap::attack( const std::string& target ) {

	std::cout << "FRAG ATTACK : ";
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

void	FragTrap::highFivesGuys( void ) {

	std::cout << this->_name;
	if (this->_hitPoints == 0)
		std::cout << " is attempting to raise his hands in the air for a High Five, but the protocol fails due to uncounciousness!" << std::endl;
	else
		std::cout << " raise his hands in the air and shout \"High Five Guys !!\"" << std::endl;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs ) {

	if (this != &rhs) {

		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	return *this;
}
