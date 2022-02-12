#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class Claptrap {

public :

	Claptrap( void );
	Claptrap( Claptrap &src );
	Claptrap( std::string name );
	~Claptrap( void );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	Claptrap &	operator=( Claptrap const & rhs );

private :

	std::string		name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif
