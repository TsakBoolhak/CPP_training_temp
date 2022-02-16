#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap {

public :

	ClapTrap( void );
	ClapTrap( ClapTrap const & src );
	ClapTrap( std::string name );
	~ClapTrap( void );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	ClapTrap &	operator=( ClapTrap const & rhs );

private :

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif
