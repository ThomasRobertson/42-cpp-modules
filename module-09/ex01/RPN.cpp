#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN & copy)
{
	*this = copy;
}

RPN::~RPN()
{

}

RPN & RPN::operator=(const RPN & assign)
{
	if (this != &assign)
	{
		_vec = assign._vec;
	}
	return *this;
}

RPN::RPN(const char * str_input)
{
	std::string str(str_input);
	size_t pos;

	while ((pos = str.find(' ')) != std::string::npos)
	{
		if (str.substr(0, pos).length() == 0)
		{
			str.erase(0, pos + 1);
			continue ;
		}
		_vec.push_back(str.substr(0, pos));
		str.erase(0, pos + 1);
	}
	_vec.push_back(str);
}

void RPN::validate_vec() const
{
	if (_vec.size() == 0)
		throw std::runtime_error("Error: empty list.");
	for (RPN_vec_t::const_iterator it = _vec.begin(); it != _vec.end(); it ++)
	{
		std::string value = *it;
		if (value.length() != 1)
			throw std::runtime_error("Error: Value too long.");
		if (value.find_first_not_of("0123456789+-/*") != std::string::npos)
			throw std::runtime_error("Error: Invalid token.");
	}
}

void RPN::compute_operator(std::string value)
{
	if (_stack.empty())
		throw std::runtime_error("Error: stack is empty, invalid input.");
	int second_operand = _stack.top();
	_stack.pop();

	if (_stack.empty())
		throw std::runtime_error("Error: stack is empty, invalid input.");
	int first_operand = _stack.top();
	_stack.pop();

	switch (value.c_str()[0])
	{
	case '+':
		_stack.push(first_operand + second_operand);
		break;
	
	case '-':
		_stack.push(first_operand - second_operand);
		break;

	case '/':
		_stack.push(first_operand / second_operand);
		break;
	
	case '*':
		_stack.push(first_operand * second_operand);
		break;

	default:
		throw std::runtime_error("Error: invalid operatir, bad input.");
		break;
	}
}

void RPN::compute_rpn()
{
	for (RPN_vec_t::const_iterator it = _vec.begin(); it != _vec.end(); it ++)
	{
		std::string value = *it;
		if (value.find_first_not_of("1234567890") == std::string::npos)
			_stack.push(str2nbr<int>(value));
		else if (value.find_first_not_of("+-/*") == std::string::npos)
			compute_operator(value);
		else
			throw std::runtime_error("Error: unknow value.");
	}
}

int RPN::do_RPN_stuff()
{
	validate_vec();
	compute_rpn();
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Stack should be size of 1, invalid input");
	return _stack.top();
}

template<class T>
T RPN::str2nbr(std::string s)
{
	T i;
    std::stringstream ss;
	ss << s;
    ss >> i;
    if (ss.fail())
	{
        throw std::runtime_error("Error: cannot convert value, invalid input.");
    }
    return i;
}
