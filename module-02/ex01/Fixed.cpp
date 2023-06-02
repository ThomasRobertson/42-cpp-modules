#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & F)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = F.getRawBits();
}

Fixed::Fixed(int const &nbr) : _value(nbr << _nbrFractional)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const &nbr) : _value(::roundf(nbr * (1 << _nbrFractional)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&rhs != this)
	{
		_value = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void    Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat() const
{
	return static_cast<float>(getRawBits()) / ( 1 << _nbrFractional);
}

int Fixed::toInt() const
{
	return _value >> _nbrFractional;
}

std::ostream & operator<<(std::ostream &out, Fixed const & F)
{
	out << F.toFloat();
	return out;
}
