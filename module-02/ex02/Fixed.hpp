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

		bool operator>(Fixed const &) const;
		bool operator<(Fixed const &) const;
		bool operator>=(Fixed const &) const;
		bool operator<=(Fixed const &) const;
		bool operator==(Fixed const &) const;
		bool operator!=(Fixed const &) const;

		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs) const;
		Fixed operator/(Fixed const &rhs) const;
	
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);	

		static Fixed &min(Fixed &A, Fixed &B);
		static Fixed const &min(Fixed const &A, Fixed const &B);
		static Fixed &max(Fixed &A, Fixed &B);
		static Fixed const &max(Fixed const &A, Fixed const &B);

	private:
		int _value;
		static const int _nbrFractional = 8;
};

std::ostream & operator<<(std::ostream &out, Fixed const & F);

#endif
