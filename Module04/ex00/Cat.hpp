#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

public :

	Cat( void );
	Cat( Cat const & src );
	virtual ~Cat( void );

	virtual void	makeSound() const;

	Cat &	operator=( Cat const & rhs );

};

#endif
