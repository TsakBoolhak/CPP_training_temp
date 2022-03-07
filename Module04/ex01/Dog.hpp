#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

public :

					Dog();
					Dog( Dog const & src );
	virtual			~Dog();

	virtual void	makeSound() const;
	virtual Brain *	getBrain() const;

	Dog &			operator=( Dog const & rhs );

private :

	Brain			*brain;

};

#endif
