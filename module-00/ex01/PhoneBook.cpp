#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() {
	i_ = 0;
	std::cout << "PhoneBook Created." << std::endl;
}

void PhoneBook::add() {
	contacts_[i_].set_contact();
	i_++;
	if (i_ == NBR_CONTACTS)
		i_ = 0;
}

static std::string display_string(std::string input) {
	if (input.size() <= 10)
		return (input);
	input.resize(9);
	return input + ".";
}

void PhoneBook::search() {
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (unsigned int j = 0; j != NBR_CONTACTS; j++)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << j;
		std::cout << "|";
		std::cout << std::right << std::setw(10) << display_string(contacts_[j].get_first_name());
		std::cout << "|";
		std::cout << std::right << std::setw(10) << display_string(contacts_[j].get_last_name());
		std::cout << "|";
		std::cout << std::setw(10) << display_string(contacts_[j].get_nickname());
		std::cout << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}

	std::cout << "INDEX : ";
	std::string str_index;
	std::getline(std::cin, str_index);
	if (str_index.empty() || str_index.size() > 1 || std::atoi(str_index.c_str()) > NBR_CONTACTS) {
		std::cout << "Ilegal operation, calling the police and terminating user." << std::endl;
		std::cout << "Segmentation fault (core dumped)." << std::endl;
	}
	else {
		contacts_[std::atoi(str_index.c_str())].display_contact();
	}
}

void PhoneBook::execute_input(std::string input) {
	if (input == "ADD")
		PhoneBook::add();
	else if (input == "SEARCH")
		PhoneBook::search();
}
