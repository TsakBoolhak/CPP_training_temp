#include <iostream>
#include <limits>
#include "FragTrap.hpp"

int	main( void ) {

	FragTrap	defaultFragtrap;
	FragTrap	bob( "Bob" );
	FragTrap	bill( FragTrap( "Bill" ) );

	std::cout << std::endl << "--------------------------------TURN 1--------------------------------" << std::endl;

	defaultFragtrap.attack( "Training Dummy" );
	bob.attack( "Training Dummy" );
	bill.attack( "Training Dummy" );

	std::cout << std::endl;

	defaultFragtrap.takeDamage( 1 );
	bob.takeDamage( 5 );
	bill.takeDamage( std::numeric_limits<unsigned int>::max() );

	std::cout << std::endl;

	defaultFragtrap.beRepaired( std::numeric_limits<unsigned int>::max() );
	bob.beRepaired( 0 );
	bill.beRepaired( 10 );

	defaultFragtrap.highFivesGuys();
	bob.highFivesGuys();
	bill.highFivesGuys();

	std::cout << "----------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "--------------------------------TURN 2--------------------------------" << std::endl;

	defaultFragtrap.attack( "Training Dummy" );
	bob.attack( "Training Dummy" );
	bill.attack( "Training Dummy" );

	std::cout << std::endl;

	defaultFragtrap.takeDamage( std::numeric_limits<unsigned int>::max() );
	bob.takeDamage( 4 );
	bill.takeDamage( 5 );

	std::cout << std::endl;

	defaultFragtrap.beRepaired( std::numeric_limits<unsigned int>::max() );
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

	defaultFragtrap.highFivesGuys();
	bob.highFivesGuys();
	bill.highFivesGuys();

	std::cout << "----------------------------------------------------------------------" << std::endl << std::endl;

	return 0;
}
