#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal {

public :

	WrongAnimal( void );
	WrongAnimal( WrongAnimal const & src );
	~WrongAnimal( void );

	void	makeSound() const;

	std::string const & getType() const;

	WrongAnimal &	operator=( WrongAnimal const & rhs );

protected :

	std::string		type;

};

#endif
