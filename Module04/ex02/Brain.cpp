#include <string>
#include <iostream>
#include "Brain.hpp"

Brain::Brain( void ) : ideasCount (0) {

	std::cout << "Brain default constructor called" << std::endl;

	return ;
}

Brain::Brain( Brain const & src ) {

	*this = src;

	std::cout << "Brain copy constructor called" << std::endl;

	return ;
}

Brain::~Brain( void ) {

	std::cout << "Brain destructor called" << std::endl;

	return ;
}

bool	Brain::printIdea( size_t index) const {

	if ( this->ideasCount <= index )
		return FAILURE;

	std::cout << "Idea #" << index << " : " << (this->ideas)[index] << std::endl;

	return SUCCESS;
}

void	Brain::printIdeas() const {

	for ( size_t i = 0 ; i < this->ideasCount ; i++ )
		this->printIdea(i);

	return ;
}

bool	Brain::addIdea( std::string newIdea) {

	if ( newIdea.empty() || this->ideasCount >= MAX_IDEAS )
		return FAILURE;

	(this->ideas)[ideasCount] = newIdea;
	this->ideasCount++;

	return SUCCESS;
}

bool	Brain::deleteIdea( size_t index ) {

	if ( this->ideasCount <= index )
		return FAILURE;

	while ( index < this->ideasCount ) {

		if ( index + 1 == MAX_IDEAS )
			(this->ideas)[index].clear();
		else
			(this->ideas)[index] = (this->ideas)[index + 1];
		index++;
	}

	this->ideasCount--;

	return SUCCESS;
}

void	Brain::clearIdeas() {

	size_t	i = this->ideasCount;

	while (i > 0) {
		this->deleteIdea(0);
		i--;
	}
	this->ideasCount = 0;
}

size_t	Brain::getIdeasCount() const {

	return this->ideasCount;
}

std::string Brain::getIdea(size_t index) const {

	std::string ret;

	if (index < this->ideasCount)
		return (this->ideas)[index];
	else
		return ret;
}

Brain &	Brain::operator=( Brain const & rhs ) {

	if (this != &rhs) {

		this->ideasCount = rhs.ideasCount;
		for ( size_t i = 0 ; i < this->ideasCount ; i++ )
			(this->ideas)[i] = (rhs.ideas)[i];
	}

	return *this;
}
