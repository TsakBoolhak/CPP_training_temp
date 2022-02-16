#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public :

	FragTrap( void );
	FragTrap( FragTrap const & src );
	FragTrap( std::string name );
	~FragTrap( void );

	void	attack( const std::string& target );
	void	highFivesGuys( void );

	FragTrap &	operator=( FragTrap const & rhs );

private :

};

#endif
