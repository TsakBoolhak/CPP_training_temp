#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {

public :

					Cat();
					Cat( Cat const & src );
	virtual 		~Cat();

	virtual void	makeSound() const;
	virtual Brain *	getBrain() const;

	Cat &			operator=( Cat const & rhs );

private :

	Brain			*brain;

};

#endif
