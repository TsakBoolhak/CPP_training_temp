#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Zombie.hpp"
#define HORDES_COUNT 8
#define	ZOMBIE_NAME_COUNT 8

static const char *zombieNamePool[ZOMBIE_NAME_COUNT] = {

	"Average Joe",
	"Fart Fimpson",
	"Bison B.",
	"Zuybrush Zhreepwood",
	"John \"Human\" Doe",
	"Mike Tysonbie",
	"Son Biku",
	"Zombie Cycle"
};

static size_t hordeSize[HORDES_COUNT] = {

	10,
	50,
	3,
	5,
	6,
	1,
	2,
	23

};

void	announceHorde( int hordeSize, Zombie *horde) {

	for (int i = 0 ; i < hordeSize ; i++) {
		horde[i].announce();
	}
}

void	deleteHorde( int hordeSize, Zombie *horde) {

	for (int i = 0 ; i < HORDES_COUNT && i < ZOMBIE_NAME_COUNT && i < hordeSize ; i++) {
		horde->announce();
	}
}

int	main( void )
{
	Zombie	*hordes[HORDES_COUNT];

	for (int i = 0 ; i < HORDES_COUNT && i < ZOMBIE_NAME_COUNT ; i++) {

		std::string	name ( zombieNamePool[i] );
		hordes[i] = zombieHorde( hordeSize[i], name );
		if (hordes[i])
			announceHorde( hordeSize[i], hordes[i] );
	}

	for (int i = 0 ; i < HORDES_COUNT && i < ZOMBIE_NAME_COUNT ; i++) {

			delete [] hordes[i];
	}

	return 0;

}
