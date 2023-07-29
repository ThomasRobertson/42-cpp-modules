#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include <stack>
#include <sstream>

class RPN
{
	public:
	RPN(const RPN &copy);
	RPN(const char *str);
	~RPN();
	RPN & operator=(const RPN & assign);
	int do_RPN_stuff();

	private:
	RPN();

	typedef std::vector<std::string> RPN_vec_t;
	typedef std::stack<int, std::vector<int> > RPN_t;

	RPN_vec_t _vec;
	RPN_t _stack;
	void validate_vec() const;
	void compute_rpn();
	void compute_operator(std::string value);
	template<class T>
	T str2nbr(std::string s);
};