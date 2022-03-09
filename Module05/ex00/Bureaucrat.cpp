
const char *	Bureaucrat::GradeTooHighException::what() const throw() {

	return "Grade is tow high! (valid grades range : 150 - 1)";
}

const char *	Bureaucrat::GradeTooLowException::what() const throw() {

	return "Grade is tow low! (valid grades range : 150 - 1)";
}

Bureaucrat::Bureaucrat() : _grade ( 150 ), _name ( "Default Bureaucrat" ) {

	return;
}

Bureaucrat::Bureaucrat(std::string const & name, unsigned int grade) : _name ( name ) {

	if ( grade < 1 )
		throw ( this->GradeTooHighException );
	else if ( grade > 150 )
		throw ( this->GradeTooLowException );
	else
		this->_grade = grade;

	return;
}
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

};

ostream	&				operator<<(ostream & os, Bureaucrat const & rhs);

#endif
