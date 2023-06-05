#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a(10);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << std::endl << "-- COMPARISON --" << std::endl
		<< "a : " << a << std::endl
		<< "b : " << b << std::endl
		<< "a > b : " << bool(a > b) << std::endl
		<< "a < b : " << bool(a < b) << std::endl
		<< "a >= b : " << bool(a >= b) << std::endl
		<< "a <= b : " << bool(a <= b) << std::endl
		<< "a == b : " << bool(a == b) << std::endl
		<< "a != b : " << bool(a != b) << std::endl;

	a = 2.65f;
	std::cout << std::endl << "-- ARITHMETIC --" << std::endl
		<< "a : " << a << std::endl
		<< "b : " << b << std::endl
		<< "a + b : " << a + b << std::endl
		<< "a - b : " << a - b << std::endl
		<< "a * b : " << a * b << std::endl
		<< "a / b : " << a / b << std::endl;	

	a = 0;
	std::cout << std::endl << "-- INCREMENT / DECREMENT --" << std::endl
		<< "a : " << a << std::endl
		<< "++a : " << ++a << std::endl
		<< "a : " << a << std::endl
		<< "a++ : " << a++ << std::endl
		<< "a : " << a << std::endl
		<< "--a : " << --a << std::endl
		<< "a : " << a << std::endl
		<< "a-- : " << a-- << std::endl
		<< "a : " << a << std::endl;

Fixed a1(25.24f);
Fixed a2(12);
const Fixed b1(26.24f);
const Fixed b2(15);

	std::cout << std::endl << "-- MIN / MAX --" << std::endl
		<< "a1.min(a1, a2) : " << a1.min(a1, a2) << std::endl
		<< "a1.max(a1, a2) : " << a1.max(a1, a2) << std::endl
		<< "b1.min(b1, b2) : " << b1.min(b1, b2) << std::endl
		<< "b1.mbx(b1, b2) : " << b1.max(b1, b2) << std::endl;
	return 0;
}

// #include <iostream>
// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }