#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public :

	DiamondTrap( void );
	DiamondTrap( DiamondTrap const & src );
	DiamondTrap( std::string name );
	~DiamondTrap( void );

	void	whoAmI( void );
	void	attack( const std::string& target );

	DiamondTrap &	operator=( DiamondTrap const & rhs );

private :

	std::string _name;

};

#endif
