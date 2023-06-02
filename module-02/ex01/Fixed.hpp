#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &);
		Fixed(int const &);
		Fixed(float const &);
		Fixed &operator=(Fixed const &);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;

	private:
		int _value;
		static const int _nbrFractional = 8;
};

std::ostream & operator<<(std::ostream &out, Fixed const & F);

#endif
