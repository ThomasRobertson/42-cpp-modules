#include <string>
#include <iostream>
#include "whatever.hpp"

class Test
{
	public :
		Test() : _i(42), str("Hello") {}
		int getI() const {return _i;}
	private :
		int _i;
		std::string str;
};

std::ostream &operator<<(std::ostream &stream, const Test &object)
{
	stream << object.getI();
	return stream;
}

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// Test e;
	// Test f;

	// ::swap(e, f);
	// std::cout << "e = " << e << ", f = " << f << std::endl;
	// std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	// std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	return 0;
}

// class Awesome
// {
// 	public:
// 	Awesome(void) : _n(0) { }
// 	Awesome( int n ) : _n( n ) {}
// 	Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
// 	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
// 	bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
// 	bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n);}
// 	bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n);}
// 	bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
// 	bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
// 	int get_n() const { return _n; }

// 	private:
// 	int _n;
// };

// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o;}

// int main(void)
// {
// 	Awesome a(2), b(4); 
// 	swap(a, b); std::cout << a <<" " << b << std::endl;
// 	std::cout << max(a, b) << std::endl;
// 	std::cout << min(a, b) << std::endl;
// 	return (0);
// }
