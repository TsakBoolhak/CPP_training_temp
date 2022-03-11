#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form {

	public :

							RobotomyRequestForm( std::string const & target );
							~RobotomyRequestForm();

	virtual void			executeAction() const;

	private :

							RobotomyRequestForm();
							RobotomyRequestForm( RobotomyRequestForm const & src );
	RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );

	const std::string		_target;
};

#endif
