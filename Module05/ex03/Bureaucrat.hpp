#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class	Form;

class Bureaucrat {

public :

	class GradeTooHighException : public std::exception {

	public :

		virtual const char *	what() const throw();

	};

	class GradeTooLowException : public std::exception {

	public :

		virtual const char *	what() const throw();

	};

						Bureaucrat( std::string const & name, unsigned int const grade );
			 			~Bureaucrat();

	const std::string &	getName() const;
	unsigned int		getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm( Form & formToSign );
	void				executeForm( Form const & form );

	Bureaucrat &		operator=( Bureaucrat const & rhs );

private :

						Bureaucrat();
						Bureaucrat( Bureaucrat const & src );

	const std::string	_name;
	unsigned int		_grade;

};

std::ostream	&				operator<<( std::ostream & os, Bureaucrat const & rhs );

#endif
