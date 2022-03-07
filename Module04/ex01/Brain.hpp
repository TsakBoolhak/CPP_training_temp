#ifndef BRAIN_HPP
# define BRAIN_HPP

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef FAILURE
#  define FAILURE 1
# endif

# define MAX_IDEAS 100

# include <string>

class Brain {

public :

				Brain();
				Brain( Brain const & src );
				~Brain();

	bool		printIdea( size_t index ) const;
	void		printIdeas() const;
	bool		addIdea( std::string );
	bool		deleteIdea( size_t index );
	void		clearIdeas();
	size_t		getIdeasCount() const;
	std::string	getIdea( size_t index ) const;

	Brain &		operator=( Brain const & rhs );

private :

	size_t		ideasCount;
	std::string	ideas[MAX_IDEAS];

};

#endif
