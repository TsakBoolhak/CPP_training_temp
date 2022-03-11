#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#define CALL_MEMBER_FN(object,ptrToMember) ((object).*(ptrToMember))

Intern::Intern() {

	newForm[0] = &Intern::newShrub;
	newForm[1] = &Intern::newRob;
	newForm[2] = &Intern::newPres;
	newForm[3] = &Intern::wrongName;

	return ;
}

Intern::Intern( Intern const & src ) {

	(void)(src);
	newForm[0] = &Intern::newShrub;
	newForm[1] = &Intern::newRob;
	newForm[2] = &Intern::newPres;
	newForm[3] = &Intern::wrongName;

	return ;
}

Intern::~Intern() {

	return ;
}

Form *	Intern::makeForm( std::string const & name, std::string const & target ) {

	const char *	funcNames[] = { "shrubbery creation", "robotomy request", "presidential pardon" };

	int	i = 0;
	while ( i < 3 ) {

		if ( name.compare( funcNames[i] ) == 0 )
			break;
		i++;
	}
	
	return ( (*this).*(newForm[i]))(name, target);
}

Form *	Intern::newShrub( std::string const & name, std::string const & target ) {

	std::cout << "Intern creates " << name << std::endl;

	return new ShrubberyCreationForm( target );
}

Form *	Intern::newRob( std::string const & name, std::string const & target ) {

	std::cout << "Intern creates " << name << std::endl;

	return new RobotomyRequestForm( target );
}

Form *		Intern::newPres( std::string const & name, std::string const & target ) {

	std::cout << "Intern creates " << name << std::endl;

	return new PresidentialPardonForm( target );
}

Form *		Intern::wrongName( std::string const & name, std::string const & target ) {

	(void)target;

	std::cout << "Intern didn't find " << name << " in the Forms' list" << std::endl;

	return NULL;
}


Intern &	Intern::operator=( Intern const & rhs ) {

	(void)rhs;

	return *this;
}
