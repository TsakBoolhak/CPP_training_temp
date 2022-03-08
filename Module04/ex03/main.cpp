#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int	main() {

	std::cout << "--------SUBJECT'S MAIN--------" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria( new Ice() );
		src->learnMateria( new Cure() );

		ICharacter* me = new Character( "me" );

		AMateria* tmp;
		tmp = src->createMateria( "ice" );
		me->equip(tmp);
		tmp = src->createMateria( "cure" );
		me->equip(tmp);

		ICharacter* bob = new Character( "bob" );
		me->use( 0, *bob );
		me->use( 1, *bob );

		delete bob;
		delete me;
		delete src;

	}
	std::cout << "------------------------------" << std::endl;

	std::cout << std::endl << "--------FURTHER  TESTS--------" << std::endl;
	{
		
		IMateriaSource* src = new MateriaSource();
		src->learnMateria( new Ice() );
		src->learnMateria( new Ice() );
		src->learnMateria( new Ice() );
		src->learnMateria( new Ice() );

		AMateria*	tmp1 = new Cure();
		src->learnMateria( tmp1 );
		
		std::cout << std::endl;

		ICharacter* me = new Character( "me" );

		AMateria* tmp2;
		AMateria* tmp3;
		tmp2 = src->createMateria( "ice" );
		me->equip(tmp2);
		tmp3 = src->createMateria( "cure" );
		me->equip(tmp3);
		tmp3 = src->createMateria( "lol" );
		me->equip(tmp3);
		tmp3 = src->createMateria( "ice" );
		me->equip(tmp3);
		tmp3 = src->createMateria( "ice" );
		me->equip(tmp3);

		std::cout << std::endl;

		ICharacter* bob = new Character( "bob" );

		me->use( -2, *bob );
		me->use( -1, *bob );
		me->use( 0, *bob );
		me->use( 1, *bob );
		me->use( 2, *bob );
		me->use( 3, *bob );
		me->use( 4, *bob );
		me->use( 5, *bob );

		std::cout << std::endl;

		me->unequip(-1);
		me->unequip(0);
		me->unequip(4);

		std::cout << std::endl;

		me->use( -2, *bob );
		me->use( -1, *bob );
		me->use( 0, *bob );
		me->use( 1, *bob );
		me->use( 2, *bob );
		me->use( 3, *bob );
		me->use( 4, *bob );
		me->use( 5, *bob );

		std::cout << std::endl;

		tmp3 = src->createMateria( "ice" );
		me->equip(tmp3);
		tmp3 = src->createMateria( "ice" );
		me->equip(tmp3);
		tmp3 = src->createMateria( "ice" );
		me->equip(tmp3);

		std::cout << std::endl;

		me->use( -2, *bob );
		me->use( -1, *bob );
		me->use( 0, *bob );
		me->use( 1, *bob );
		me->use( 2, *bob );
		me->use( 3, *bob );
		me->use( 4, *bob );
		me->use( 5, *bob );

		delete tmp1;
		delete tmp2;
		delete tmp3;
		delete bob;
		delete me;
		delete src;
	}
	std::cout << "------------------------------" << std::endl;


	return 0;
}
