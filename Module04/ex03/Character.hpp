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
							~Character();

		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		Character &			operator=( Character const & src );

	private:

		std::string	name;
		Inventory	inv;
};

# endif
