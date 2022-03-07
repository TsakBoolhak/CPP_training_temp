#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "Inventory.hpp"

class MateriaSource : public IMateriaSource {

	public :

								MateriaSource();
								MateriaSource( MateriaSource const & src );
		virtual					~MateriaSource();

		virtual void			learnMateria( AMateria* );
		virtual AMateria *		createMateria( std::string const & type );
		virtual MateriaSource &	operator=( MateriaSource const & rhs );
	
	private :

		Inventory 				inv;
};

# endif
