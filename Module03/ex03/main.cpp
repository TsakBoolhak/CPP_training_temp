#include <iostream>
#include <limits>
#include "DiamondTrap.hpp"

int	main( void ) {

	DiamondTrap	defaultDiamondtrap;
	DiamondTrap	bob( "Bob" );
	DiamondTrap	bill( DiamondTrap( "Bill" ) );

	std::cout << std::endl << "--------------------------------TURN 1--------------------------------" << std::endl;

	defaultDiamondtrap.attack( "Training Dummy" );
	bob.attack( "Training Dummy" );
	bill.attack( "Training Dummy" );

	std::cout << std::endl;

	defaultDiamondtrap.takeDamage( 1 );
	bob.takeDamage( 5 );
	bill.takeDamage( std::numeric_limits<unsigned int>::max() );

	std::cout << std::endl;

	defaultDiamondtrap.beRepaired( std::numeric_limits<unsigned int>::max() );
	bob.beRepaired( 0 );
	bill.beRepaired( 10 );

	std::cout << std::endl;

	defaultDiamondtrap.guardGate();
	bob.guardGate();
	bill.guardGate();

	std::cout << std::endl;

	defaultDiamondtrap.highFivesGuys();
	bob.highFivesGuys();
	bill.highFivesGuys();

	std::cout << std::endl;

	defaultDiamondtrap.whoAmI();
	bob.whoAmI();
	bill.whoAmI();

	std::cout << "----------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "--------------------------------TURN 2--------------------------------" << std::endl;

	defaultDiamondtrap.attack( "Training Dummy" );
	bob.attack( "Training Dummy" );
	bill.attack( "Training Dummy" );

	std::cout << std::endl;

	defaultDiamondtrap.takeDamage( std::numeric_limits<unsigned int>::max() );
	bob.takeDamage( 4 );
	bill.takeDamage( 5 );

	std::cout << std::endl;

	defaultDiamondtrap.beRepaired( std::numeric_limits<unsigned int>::max() );
	bob.beRepaired( 3 );
	bill.beRepaired( 10 );

	std::cout << "----------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "--------------------------------TURN 3--------------------------------" << std::endl;

	bob.attack( "Training Dummy" );
	bob.beRepaired( 1 );

	std::cout << "----------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "--------------------------------TURN 4--------------------------------" << std::endl;

	bob.attack( "Training Dummy" );
	bob.beRepaired( 1 );

	std::cout << "----------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "--------------------------------TURN 5--------------------------------" << std::endl;

	bob.attack( "Training Dummy" );
	bob.beRepaired( 0 );

	std::cout << "----------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "--------------------------------TURN 6--------------------------------" << std::endl;

	bob.attack( "Training Dummy" );
	bob.beRepaired( 1 );

	defaultDiamondtrap.guardGate();
	bob.guardGate();
	bill.guardGate();

	std::cout << std::endl;

	defaultDiamondtrap.highFivesGuys();
	bob.highFivesGuys();
	bill.highFivesGuys();

	std::cout << std::endl;

	defaultDiamondtrap.whoAmI();
	bob.whoAmI();
	bill.whoAmI();

	std::cout << "----------------------------------------------------------------------" << std::endl << std::endl;

	return 0;
}
