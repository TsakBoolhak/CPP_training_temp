#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

public :

	Cat( void );
	Cat( Cat const & src );
	virtual ~Cat( void );

	virtual void	makeSound() const;
	virtual Brain	*getBrain() const;

	Cat &	operator=( Cat const & rhs );

private :

	Brain	*brain;

};

#endif
