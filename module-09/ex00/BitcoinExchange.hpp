#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <ctime>

#define SSTR(x) static_cast<std::ostringstream &>(( std::ostringstream() << std::dec << x ) ).str()

class BitcoinExchange
{
	public:
	BitcoinExchange();
	BitcoinExchange(std::ifstream & data_csv);
	BitcoinExchange(const BitcoinExchange & copy);
	~BitcoinExchange();

	BitcoinExchange & operator=(const BitcoinExchange & assign);

	class ValueIsInvalid : public std::exception
	{
		const char *what() const throw();
	};
	class DateIsInvalid : public std::exception
	{
		const char *what() const throw();
	};
	class FileIsInvalid : public std::exception
	{
		const char *what() const throw();
	};

	void print_exchange();
	
	void process_input(std::ifstream & input);

	private:
	typedef std::map<std::time_t, float> echange_rates_t;
	echange_rates_t _echange_rates;

	static std::time_t get_date(std::string input, std::string delimiter);
	static float get_value(std::string input, std::string delimiter);
	template<class T>
	static bool str2nbr (T &i, std::string s);
	std::string get_date(const std::time_t & date);
	float get_exchange_rate(std::time_t date);
};
