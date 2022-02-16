#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public :

	ScavTrap( void );
	ScavTrap( ScavTrap const & src );
	ScavTrap( std::string name );
	~ScavTrap( void );

	void	attack( const std::string& target );
	void	guardGate();

	ScavTrap &	operator=( ScavTrap const & rhs );

private :

};

#endif
