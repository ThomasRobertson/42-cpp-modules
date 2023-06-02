#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &);
		Fixed &operator=(Fixed const &);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);

	private:
		int _value;
		static const int _nbrFractional = 8;
};

#endif
