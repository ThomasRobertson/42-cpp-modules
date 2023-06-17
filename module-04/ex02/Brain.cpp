#include "Brain.hpp"

const std::string Brain::_className = "Brain";

// Constructors
Brain::Brain()
{
	std::cout << "Default Constructor called of " << _className << std::endl;
}

Brain::Brain(const Brain &copy) : _ideas(copy._ideas)
{
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Destructor called of " << _className << std::endl;
}

// Operators
Brain & Brain::operator=(const Brain &assign)
{
	if (this != &assign)
	{
		std::copy(assign._ideas, assign._ideas + sizeof(*assign._ideas) / sizeof(assign._ideas), _ideas);
	}
	return *this;
}

void Brain::setIdeas(std::string idea)
{
	for (size_t i = 0; i != (sizeof(_ideas) / sizeof(*_ideas)); i++)
		_ideas[i] = idea;
}

std::string Brain::getFirstIdea() const
{
	return (_ideas[0]);
}
