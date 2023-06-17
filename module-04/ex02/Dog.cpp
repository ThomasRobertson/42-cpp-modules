#include "Dog.hpp"

const std::string Dog::_className = "Dog";

// Constructors
Dog::Dog() : Animal::Animal("Dog")
{
	_brain = new Brain;
	std::cout << "Default Constructor called of " << _className << std::endl;
}

Dog::Dog(const Dog &copy) : Animal::Animal(copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

// Destructor
Dog::~Dog()
{
	delete _brain;
	std::cout << "Destructor called of " << _className << std::endl;
}

// Operators
Dog & Dog::operator=(const Dog &assign)
{
	if (this != &assign)
	{
		_brain = new Brain(*assign._brain);
		_type = assign._type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Waf Waf" << std::endl;
}

void Dog::setIdeas(std::string idea)
{
	_brain->setIdeas(idea);
}

std::string Dog::getFirstIdea() const
{
	return (_brain->getFirstIdea());
}