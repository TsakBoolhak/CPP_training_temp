#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) : Form( "presidential pardon", 25, 5 ), _target ( target ) {

	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form( src.getName(), src.getSigningGrade(), src.getExecutingGrade() ), _target ( src._target ) {

	return ;
}

PresidentialPardonForm::~PresidentialPardonForm() {

	return ;
}

void	PresidentialPardonForm::executeAction() const {

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {

	(void)rhs;

	return *this;
}

PresidentialPardonForm::PresidentialPardonForm() : Form( "presidential pardon", 25, 5 ), _target ( "Default target" ) {

	return ;
}
