#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(const AMateria &assign)
{
	(void)assign;
	return *this;
}

std::string const & AMateria::getType() const
{
	return(_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "I don't know what " << "is..." << std::endl;
}