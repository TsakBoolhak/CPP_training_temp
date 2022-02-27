#ifndef INVENTORY_HPP
# define INVENTORY_HPP

# define INVENTORY_SIZE 4

# include "AMateria.hpp"

class Inventory {

	public:

					Inventory();
					Inventory(Inventory const & src);
					~Inventory();

		AMateria	*getMateria(int idx) const;
		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter& target) const;
		Inventory &	operator=( Inventory const & src );

	private:

		AMateria	*materias[INVENTORY_SIZE];
};

# endif
