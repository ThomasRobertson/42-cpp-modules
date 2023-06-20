#include "Ice.hpp"

// Constructors
Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	*this = copy;
}

// Destructor
Ice::~Ice()
{
}


// Operators
Ice & Ice::operator=(const Ice &assign)
{
	(void) assign;
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
