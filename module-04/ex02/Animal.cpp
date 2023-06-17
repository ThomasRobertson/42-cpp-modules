#include "Animal.hpp"

const std::string Animal::_className = "Animal";

// Constructors
Animal::Animal()
{
	std::cout << "Default Constructor called of " << _className << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Fields Constructor called of " << _className << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Destructor called of " << _className << std::endl;
}

// Operators
Animal & Animal::operator=(const Animal &assign)
{
	if (this != &assign)
	{
		_type = assign._type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return (_type);
}
