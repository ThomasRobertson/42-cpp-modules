#include "iter.hpp"

int main()
{
	int arr_int[] = {41, 21 , 554, 65, 41, 21, 28, 32};

	iter<int>(arr_int, sizeof arr_int / sizeof *arr_int, &display<int>);
	std::cout << std::endl;
	iter<int>(arr_int, sizeof arr_int / sizeof *arr_int, &increment<int>);
	iter<int>(arr_int, sizeof arr_int / sizeof *arr_int, &display<int>);
	std::cout << std::endl;

	float arr_float[] = {41.25, 21.845 , 554.41, 65.12, 41.145, 2.1, 28.12, 3212.4};

	iter<float>(arr_float, sizeof arr_float / sizeof *arr_float, &display<float>);
	std::cout << std::endl;
	iter<float>(arr_float, sizeof arr_float / sizeof *arr_float, &increment<float>);
	iter<float>(arr_float, sizeof arr_float / sizeof *arr_float, &display<float>);
	std::cout << std::endl;

	std::string arr_string[] = {"toto", "hi", "coucou", "hola"};

	iter<std::string>(arr_string, sizeof arr_string / sizeof *arr_string, &display<std::string>);
	std::cout << std::endl;
	// iter<std::string>(arr_string, sizeof arr_string / sizeof *arr_string, &increment<std::string>);
	// iter<std::string>(arr_string, sizeof arr_string / sizeof *arr_string, &display<std::string>);
	// std::cout << std::endl;
}

// class Awesome
// {
// 	public:
// 	Awesome( void ) : _n( 42 ) { return; }
// 	int get( void ) const { return this->_n; }

// 	private:
// 	int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main()
// {
// 	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// 	Awesome tab2[5];

// 	iter( tab, 5, print );
// 	iter( tab2, 5, print ); 

// 	return 0;
// }