#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}


// Destructor
ScalarConverter::~ScalarConverter()
{
}


// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void)assign;
	return *this;
}

void ScalarConverter::printChar(std::string input)
{
	char input_char = static_cast<int>(TConvertType<int>(input));
	if (isgraph(input_char))
		std::cout << "char: '" << input_char << "'\n";
	else
		std::cout << "char: non displayable\n";
	std::cout << "int: " << static_cast<int>(input_char) << "\n"
		<< "float: " << static_cast<float>(input_char) << ".0f\n";
	std::cout << "double: " << static_cast<double>(input_char) << ".0" << std::endl;
}

void ScalarConverter::printInt(std::string input)
{
	int input_int = TConvertType<int>(input);
	if (input_int >= SCHAR_MIN && input_int <= SCHAR_MAX && isgraph(input_int))
		std::cout << "char: '" << static_cast<char>(input_int) << "'\n";
	else
		std::cout << "char: non displayable\n";
	std::cout << "int: " << (input_int) << "\n";

	if (TCanCreate<float>(input))
		std::cout << "float: " << static_cast<float>(input_int) << ".0f\n";
	else
		std::cout << "float: incompatible\n";

	if (TCanCreate<double>(input))
		std::cout << "double: " << static_cast<double>(input_int) << ".0" << std::endl;
	else
		std::cout << "double: incompatible" << std::endl;
}

void ScalarConverter::printFloat(std::string input)
{
	float input_float;
	if (input == "nan")
		input_float = NAN;
	else
		input_float = TConvertType<float>(input);

	if (::round(input_float) == input_float && input_float >= SCHAR_MIN
			&& input_float <= SCHAR_MAX && isgraph(static_cast<int>(input_float)))
		std::cout << "char: '" << static_cast<char>(input_float) << "'\n";
	else
		std::cout << "char: non displayable\n";

	if (::round(input_float) == static_cast<int>(input_float))
		std::cout << "int: " << static_cast<int>(input_float) << "\n";
	else
		std::cout << "int: incompatible\n";

	std::cout << "float: " << input_float;
	if (input_float == static_cast<int>(input_float))
		std::cout << ".0f\n";
	else
		std::cout << "f\n";

	std::cout << "double: " << static_cast<double>(input_float);
	if (input_float == static_cast<int>(input_float))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void ScalarConverter::printDouble(std::string input)
{
	double input_double = TConvertType<double>(input);
	if (::round(input_double) == input_double && input_double >= SCHAR_MIN &&
			input_double <= SCHAR_MAX && isgraph(static_cast<int>(input_double)))
		std::cout << "char: '" <<static_cast<char>(input_double) << "'\n";
	else
		std::cout << "char: non displayable\n";
	if (::round(input_double) == static_cast<int>(input_double))
		std::cout << "int: " << static_cast<int>(input_double) << "\n";
	else
		std::cout << "int: incompatible\n";
	if (TCanCreate<float>(input))
	{
		std::cout << "float: " << static_cast<float>(input_double);
		if (input_double == static_cast<int>(input_double))
			std::cout << ".0f\n";
			else
		std::cout << "f\n";
	}
	else
		std::cout << "float: incompatible\n";
	std::cout << "double: " << static_cast<double>(input_double);	
	if (input_double == static_cast<int>(input_double))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void ScalarConverter::printUnknown(std::string input)
{
	std::string char_representation;
	std::string int_representation;
	std::string float_representation;
	std::string double_representation;

	if (input == "+inf" || input == "-inf")
	{
		char_representation = "incompatible";
		int_representation = "incompatible";
		float_representation = input + "f";
		double_representation = input;
	}
	else
	{
		char_representation = "unknown";
		int_representation = "unknown";
		float_representation = "unknown";
		double_representation = "unknown";		
	}

	std::cout << "char: " << char_representation << "\n"
		<< "int: " << int_representation << "\n"
		<< "float: " << float_representation << "\n"
		<< "double: " << double_representation << std::endl;
}

void ScalarConverter::printTypes(std::string input, _type types)
{
	switch (types)
	{
	case char_type:
		printChar(input);
		break;
	case int_type:
		printInt(input);
		break;
	case float_type:
		printFloat(input);
		break;
	case double_type:
		printDouble(input);
		break;
	case unknown_type:
		printUnknown(input);
		break;
	default:
		break;
	}
}

ScalarConverter::_type ScalarConverter::findType(std::string input)
{
	if (input == "nan")
		return float_type;
	else if (*input.rbegin() == 'f')
	{
		input.resize(input.size()-1);
		if (TCanCreate<float>(input))
			return float_type;
	}

	bool canBeInt = TCanCreate<int>(input);
	bool canBeDouble = TCanCreate<double>(input);

	if (!canBeInt && canBeDouble)
		return double_type;
	else if (canBeInt)
	{
		int input_int = TConvertType<int>(input);
		if (input_int >= SCHAR_MIN && input_int <= SCHAR_MAX)
			return char_type;
		else
			return int_type;
	}
	else
		return unknown_type;
}

void ScalarConverter::convert(std::string input)
{
	_type type = findType(input);
	printTypes(input, type);
}
