#include "Cat.hpp"

const std::string Cat::_className = "Cat";

// Constructors
Cat::Cat() : Animal::Animal("Cat")
{
	_brain = new Brain;
	std::cout << "Default Constructor called of " << _className << std::endl;
}

Cat::Cat(const Cat &copy) : Animal::Animal(copy)
{
	_brain = copy._brain;
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

// Destructor
Cat::~Cat()
{
	delete _brain;
	std::cout << "Destructor called of " << _className << std::endl;
}

// Operators
Cat & Cat::operator=(const Cat &assign)
{
	if (this != &assign)
	{
		_brain = assign._brain;
		_type = assign._type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "I want to kill my owner." << std::endl;
}

void Cat::setIdeas(std::string idea)
{
	_brain->setIdeas(idea);
}

std::string Cat::getFirstIdea() const
{
	return (_brain->getFirstIdea());
}