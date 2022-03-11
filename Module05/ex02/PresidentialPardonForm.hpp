#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form {

	public :

						PresidentialPardonForm( std::string const & target );
						~PresidentialPardonForm();

	virtual void		executeAction() const;

	private :

						PresidentialPardonForm();
						PresidentialPardonForm( PresidentialPardonForm const & src );
						PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );

	const std::string	_target;
};

#endif
