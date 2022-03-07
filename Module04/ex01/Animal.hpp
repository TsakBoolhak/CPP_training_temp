#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include "Brain.hpp"

class Animal {

public :

						Animal();
						Animal( Animal const & src );
	virtual				~Animal();

	virtual void		makeSound() const;
	virtual Brain		*getBrain() const;

	std::string const &	getType() const;

	Animal &			operator=( Animal const & rhs );

protected :

	std::string			type;

};

#endif
