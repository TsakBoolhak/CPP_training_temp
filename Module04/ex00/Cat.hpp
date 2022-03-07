#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

public :

					Cat();
					Cat( Cat const & src );
	virtual			~Cat();

	virtual void	makeSound() const;

	Cat &			operator=( Cat const & rhs );

};

#endif
