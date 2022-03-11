#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <string>
# include "Form.hpp"

# define SHRUBBERY_TREE "" \
"      ,%%%%%%%%%,\n" \
"     %%o%%//%%%%%%\n" \
"    %%%%\\%%%<%%%%%\n" \
"    %%>%%%/%%%%o%%\n" \
"    %%%%%o%%\\%%//%\n" \
"    %\\o%\\%%/%o/%%'\n" \
"     '%%\\ `%/%%%'\n" \
"       '%| |%|%'\n" \
"         | | (O\n" \
"         | | |\\\n" \
"         | | >>\n" \
"         | |\n" \
"        /   \\\n" \

class ShrubberyCreationForm : public Form {

	public :

							ShrubberyCreationForm( std::string const & target );
							~ShrubberyCreationForm();

	virtual void			executeAction() const;


	private :

							ShrubberyCreationForm();
							ShrubberyCreationForm( ShrubberyCreationForm const & src );
	ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );

	const std::string		_target;
};

#endif
