#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Inventory.hpp"

class Character : public ICharacter {

	public:

							Character();
							Character( std::string const & name );
							Character(Character const & src);
		virtual				~Character();

		virtual				std::string const & getName() const;
		virtual void		equip(AMateria* m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter& target) const;
		virtual Character &	operator=( Character const & src );

	private:

		std::string	name;
		Inventory	inv;
};

# endif
