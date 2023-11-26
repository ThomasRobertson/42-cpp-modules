#include "BitcoinExchange.hpp"
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::ifstream &data_csv) {
  std::string input_str;
  std::getline(data_csv, input_str);
  if (input_str != "date,exchange_rate")
    throw FileIsInvalid();
  input_str.clear();
  while (std::getline(data_csv, input_str)) {
    if (input_str.find_first_not_of("0123456789-,.") != std::string::npos ||
        std::count(input_str.begin(), input_str.end(), '-') != 2 ||
        std::count(input_str.begin(), input_str.end(), ',') != 1)
      throw FileIsInvalid();
    _echange_rates[get_date(input_str, ",")] = get_value(input_str, ",");
    input_str.clear();
  }
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) { *this = copy; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign) {
  if (this != &assign) {
    _echange_rates = assign._echange_rates;
  }
  return (*this);
}

std::time_t BitcoinExchange::get_date(std::string input,
                                      std::string delimiter) {
  std::string::size_type pos1 = input.find_first_of('-');
  std::string year = input.substr(0, pos1);
  std::string::size_type pos2 = input.find_first_of('-', pos1 + 1);
  std::string month = input.substr(pos1 + 1, pos2 - pos1 - 1);
  std::string::size_type pos3 = input.find_first_of(delimiter, pos2 + 1);
  std::string day = input.substr(pos2 + 1, pos3 - pos2 - 1);

  std::tm date;
  int year_int;
  int month_int;
  int day_int;

  if (year.size() != 4 || month.size() != 2 || day.size() != 2)
    throw DateIsInvalid();

  if (!str2nbr(year_int, year) || !str2nbr(month_int, month) ||
      !str2nbr(day_int, day))
    throw DateIsInvalid();
  date.tm_year = year_int - 1900;
  date.tm_mon = month_int - 1;
  date.tm_mday = day_int;
  date.tm_hour = 0;
  date.tm_min = 0;
  date.tm_sec = 0;
  date.tm_isdst = -1;

  struct tm copy;
  copy.tm_sec = date.tm_sec;
  copy.tm_min = date.tm_min;
  copy.tm_hour = date.tm_hour;
  copy.tm_mday = date.tm_mday;
  copy.tm_mon = date.tm_mon;
  copy.tm_year = date.tm_year;
  copy.tm_isdst = date.tm_isdst;

  std::time_t time = std::mktime(&date);
  if (time == -1)
    throw DateIsInvalid();
  if (copy.tm_mday != date.tm_mday || copy.tm_mon != date.tm_mon ||
      copy.tm_year != date.tm_year) {
    throw DateIsInvalid();
  }

  return time;
}

float BitcoinExchange::get_value(std::string input, std::string delimiter) {
  std::string value_str =
      input.substr(input.find_first_of(delimiter) + delimiter.length());
  std::string integer = value_str.substr(0, value_str.find('.'));
  float value;

  if (!str2nbr(value, value_str))
    throw std::invalid_argument("bad input.");
  if (delimiter == " | " && (value > 1000 || integer.size() > 5))
    throw std::out_of_range("too large a number.");
  if (value < 0)
    throw std::out_of_range("not a positive number.");

  return (value);
}

template <class T> bool BitcoinExchange::str2nbr(T &i, std::string s) {
  std::stringstream ss;
  ss << s;
  ss >> i;
  if (ss.fail()) {
    return false;
  }
  return true;
}

void BitcoinExchange::print_exchange() {
  for (echange_rates_t::iterator it = _echange_rates.begin();
       it != _echange_rates.end(); it++)
    std::cout << get_date(it->first) << "," << it->second << std::endl;
}

std::string BitcoinExchange::get_date(const std::time_t &date) {
  std::tm date_tm = *(localtime(&date));

  std::stringstream date_str;
  date_str << (date_tm.tm_year + 1900) << "-" << std::setfill('0')
           << std::setw(2) << (date_tm.tm_mon + 1) << "-" << std::setfill('0')
           << std::setw(2) << date_tm.tm_mday;

  return date_str.str();
}

const char *BitcoinExchange::ValueIsInvalid::what() const throw() {
  return "Value is invalid";
}

const char *BitcoinExchange::FileIsInvalid::what() const throw() {
  return "File is invalid";
}

const char *BitcoinExchange::DateIsInvalid::what() const throw() {
  return "date is invalid";
}

void BitcoinExchange::process_input(std::ifstream &input) {
  std::string input_str;
  std::getline(input, input_str);
  if (input_str != "date | value")
    throw FileIsInvalid();
  input_str.clear();
  while (std::getline(input, input_str)) {
    if (input_str.find_first_not_of("0123456789- |.") != std::string::npos ||
        std::count(input_str.begin(), input_str.end(), '-') != 2 ||
        std::count(input_str.begin(), input_str.end(), '|') != 1 ||
        std::count(input_str.begin(), input_str.end(), ' ') != 2 ||
        std::count(input_str.begin(), input_str.end(), '.') > 1 ||
        input_str.find(" | ") == std::string::npos) {
      std::cout << "Error: bad input => " << input_str << std::endl;
      continue;
    }
    try {
      std::time_t date = get_date(input_str, " | ");
      if (date < _echange_rates.begin()->first)
        throw DateIsInvalid();
      float value = get_value(input_str, " | ");
      std::cout << get_date(date) << " => " << value << " => "
                << get_exchange_rate(date) * value << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << " => " << input_str << '\n';
    }
    input_str.clear();
  }
}

float BitcoinExchange::get_exchange_rate(std::time_t date) {
  try {
    return _echange_rates.at(date);
  } catch (const std::exception &e) {
  }
  echange_rates_t::iterator it = _echange_rates.lower_bound(date);
  if (it == _echange_rates.begin())
    throw DateIsInvalid();
  --it;
  return (it->second);
}