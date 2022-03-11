#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"

class Intern {

	public :

									Intern();
									~Intern();

		Form *						makeForm( std::string const & name, std::string const & target );

		Intern &					operator=( Intern const & rhs );

	private :

									Intern( Intern const & src );

		Form *		newShrub( std::string const & name, std::string const & target );
		Form *		newRob( std::string const & name, std::string const & target );
		Form *		newPres( std::string const & name, std::string const & target );
		Form *		wrongName( std::string const & name, std::string const & target );

		typedef Form* (Intern::*funcPtr)(std::string const &, std::string const &);
		funcPtr	newForm[4];
};

#endif
