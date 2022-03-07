#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public :

				WrongCat();
				WrongCat( WrongCat const & src );
				~WrongCat();

	void		makeSound() const;

	WrongCat &	operator=( WrongCat const & rhs );

};

#endif
