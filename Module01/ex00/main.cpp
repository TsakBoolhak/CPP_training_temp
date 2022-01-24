#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Zombie.hpp"
#define ZOMBIE_COUNT_MAX 128
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

int	main(int ac, char **av)
{
	Zombie	*zombiePool[ZOMBIE_COUNT_MAX];

	std::srand(std::time(NULL));

	zombiePool[0] = newZombie( "[zombie #0] PatientZero" );

	zombiePool[0]->announce();
	randomChump( "[chump #0] JustARandomChump" );

	for (int i = 1; i < ZOMBIE_COUNT_MAX && i < ac; i++) {

		std::stringstream zombieName;
		std::stringstream chumpName;

		zombieName << "[zombie #" << i << "] " << av[i];
		zombiePool[i] = newZombie( zombieName.str() );

		chumpName << "[chump #" << i << "] " << zombieNamePool[rand() % ZOMBIE_NAME_COUNT];
		randomChump( chumpName.str() );
	}

	for (int i = 0; i < ZOMBIE_COUNT_MAX && i < ac; i++) {

		if (zombiePool[i] != NULL)
			zombiePool[i]->announce();
	}

	for (int i = 0; i < ZOMBIE_COUNT_MAX && i < ac; i++) {

		delete zombiePool[i];
		zombiePool[i] = NULL;
	}
	
	return 0;
}
