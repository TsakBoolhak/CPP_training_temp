#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {

public :

						Animal();
						Animal( Animal const & src );
	virtual 			~Animal();

	virtual void		makeSound() const;

	std::string const &	getType() const;

	Animal &			operator=( Animal const & rhs );

protected :

	std::string			type;

};

#endif
