#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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
						Bureaucrat( Bureaucrat const & src );
			 			~Bureaucrat();

	const std::string &	getName() const;
	unsigned int		getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	Bureaucrat &		operator=( Bureaucrat const & rhs );

private :

	const std::string	_name;
	unsigned int		_grade;
						Bureaucrat();

};

std::ostream	&				operator<<( std::ostream & os, Bureaucrat const & rhs );

#endif
