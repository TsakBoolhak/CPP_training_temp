#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {

public :

					Dog();
					Dog( Dog const & src );
	virtual 		~Dog();

	virtual void	makeSound() const;
	virtual Brain	*getBrain() const;

	Dog &			operator=( Dog const & rhs );

private :

	Brain			*brain;

};

#endif
