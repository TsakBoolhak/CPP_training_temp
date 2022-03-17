#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class Form {

public :

	class GradeTooHighException : public std::exception {

	public :

		virtual const char *	what() const throw();

	};

	class GradeTooLowException : public std::exception {

	public :

		virtual const char *	what() const throw();

	};

							Form( std::string const & name, unsigned int const signingGrade, unsigned int const executingGrade );
							Form( Form const & src );
				 			~Form();

	const std::string &		getName() const;
	unsigned int			getSigningGrade() const;
	unsigned int			getExecutingGrade() const;
	bool					getIsSigned() const;
	bool					beSigned( Bureaucrat const & signingBureaucrat );

	Form &					operator=( Form const & rhs );

private :

							Form();

	const std::string		_name;
	bool					_isSigned;
	const unsigned int		_signingGrade;
	const unsigned int		_executingGrade;

};

std::ostream	&			operator<<( std::ostream & os, Form const & rhs );

#endif
