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

						Bureaucrat(unsigned int grade);
						Bureaucrat( Bureaucrat const & src );
			 			~Bureaucrat();

	const std::string &	getName() const;
	const unsigned int	getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	Bureaucrat &		operator=( Bureaucrat const & rhs );

private :

	const std::string	_name;
	unsigned int		_grade;
						Bureaucrat();

};

ostream	&				operator<<(ostream & os, Bureaucrat const & rhs);

#endif
