#include "Cure.hpp"

// Constructors
Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	*this = copy;
}

// Destructor
Cure::~Cure()
{
}


// Operators
Cure & Cure::operator=(const Cure &assign)
{
	(void) assign;
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
