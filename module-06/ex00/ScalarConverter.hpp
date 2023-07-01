#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>

#include "TCanCreate.hpp"
#include "TConvertType.hpp"

class ScalarConverter
{
	public:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		// Destructor
		~ScalarConverter();
		
		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);
		
		static void convert(std::string input);
	private:
		enum _type
		{
			char_type,
			int_type,
			float_type,
			double_type,
			unknown_type
		};
		
		static _type findType(std::string input);
		static void printTypes(std::string input, _type type);
		static void printChar(std::string input);
		static void printInt(std::string input);
		static void printFloat(std::string input);
		static void printDouble(std::string input);
		static void printUnknown(std::string input);
};

#endif