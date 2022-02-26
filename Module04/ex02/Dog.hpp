#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {

public :

	Dog( void );
	Dog( Dog const & src );
	virtual ~Dog( void );

	virtual void	makeSound() const;
	virtual Brain	*getBrain() const;

	Dog &	operator=( Dog const & rhs );

private :

	Brain	*brain;

};

#endif
