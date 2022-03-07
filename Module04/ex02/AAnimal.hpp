#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <string>
# include "Brain.hpp"

class AAnimal {

public :

						AAnimal();
						AAnimal( AAnimal const & src );
	virtual 			~AAnimal();

	virtual void		makeSound() const = 0;
	virtual Brain *		getBrain() const = 0;

	std::string const & getType() const;

	AAnimal &			operator=( AAnimal const & rhs );

protected :

	std::string			type;

};

#endif
