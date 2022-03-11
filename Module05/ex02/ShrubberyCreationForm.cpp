#include <fstream>
#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : Form( "shrubbery creation", 145, 137 ), _target ( target ) {

	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : Form( src.getName(), src.getSigningGrade(), src.getExecutingGrade() ), _target ( src._target ) {

	return ;
}

void	ShrubberyCreationForm::executeAction() const {

	std::ofstream	file;
	std::string		filename( this->_target + "_shrubbery" );

	file.open( filename.c_str(), std::ifstream::out );

	if ( file.fail() )
		throw ( std::runtime_error( "Couldn't open file" ) );

	file << SHRUBBERY_TREE;

	file.close();

	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {

	(void)rhs;

	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm() : Form( "shrubbery creation", 145, 137 ), _target ( "Default target" ) {

	return ;
}
