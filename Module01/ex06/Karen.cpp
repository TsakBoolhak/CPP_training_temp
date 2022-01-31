#include "Karen.hpp"
#include <iostream>
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))


Karen::Karen( void ) {
	
	array[0] = &Karen::debug;
	array[1] = &Karen::info;
	array[2] = &Karen::warning;
	array[3] = &Karen::error;
	array[4] = &Karen::unknown;
	return ;
}

Karen::~Karen( void ) {

	return ;
}


void	Karen::complain( std::string levelInput ) {

	const char	*level[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int	index = 0;

	while (index < 4) {
		if (levelInput.compare(level[index]) == 0)
			break;
		index++;
	}
	CALL_MEMBER_FN(*this, array[index]) ();

	return ;
}

void	Karen::debug( void ) {

	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;

	return ;
}

void	Karen::info( void ) {

	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

	return ;
}

void	Karen::warning( void ) {

	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;

	return ;
}

void	Karen::error( void ) {
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;

	return ;
}

void	Karen::unknown( void ) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

	return ;
}
