#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
  {
    Weapon	club2 = Weapon("crude spiked club");

	HumanA bob("Bob", club2);
	bob.attack();
	club2.setType("some other type of club");
	bob.attack();
  }
  {
    Weapon	club = Weapon("crude spilolked club");

	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
  }

  return 0;
}
