#include "WrongAnimal.hpp"

const std::string WrongAnimal::_className = "WrongAnimal";

// Constructors
WrongAnimal::WrongAnimal()
{
	std::cout << "Default Constructor called of " << _className << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type)
{
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Fields Constructor called of " << _className << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called of " << _className << std::endl;
}

// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	if (this != &assign)
	{
		_type = assign._type;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Piou piou" << std::endl;
}
