#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class	ICharacter;

class AMateria {

protected:

						AMateria();
						AMateria( AMateria const & src );
	std::string			type;

public:

						AMateria( std::string const & type );
	virtual 			~AMateria( void );

	AMateria &			operator=( AMateria const & rhs );

	std::string const & getType() const;

	virtual AMateria * 	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
