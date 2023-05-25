#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

#define NBR_CONTACTS 8

class PhoneBook {
	public:
	PhoneBook();
	void execute_input(std::string input);

	private:
	unsigned int i_;
	Contact contacts_[NBR_CONTACTS];
	void add();
	void search();
	void exit();
};

#endif
