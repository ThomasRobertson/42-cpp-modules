#include "Contact.hpp"
#include <iostream>

std::string Contact::get_first_name () const
{
	return first_name_;
};

std::string Contact::get_last_name () const
{
	return last_name_;
};

std::string Contact::get_nickname () const
{
	return nickname_;
};

std::string Contact::get_phone_number () const
{
	return phone_number_;
};

std::string Contact::get_darkest_secret () const
{
	return "Sorry, I can't tell.";
};

void Contact::display_contact() {
	std::cout << "First name : " << get_first_name() << std::endl;
	std::cout << "Last name : " << get_last_name() << std::endl;
	std::cout << "Nickname : " << get_nickname() << std::endl;
	std::cout << "Phone number : " << get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << get_darkest_secret() << std::endl;
}

bool Contact::contact_is_valid()
{
	if (first_name_.empty() || last_name_.empty() || nickname_.empty() ||
			phone_number_.empty() || darkest_secret_.empty()) {
		std::cout << "One or more membrane is empty" << std::endl;
		return false;
	}
	for (std::string::const_iterator i = phone_number_.begin(); i != phone_number_.end(); i++)
	{
		if (!isdigit(*i) && !isspace(*i) && *i != '+') {
			std::cout << "Invalid phone number format." << std::endl;
			return false;
		}
	}
	return true;
}

void Contact::set_contact()
{
	std::cout << "Please will out the form bellow." << std::endl;
	do {
		std::cout << "First name : ";
		std::getline(std::cin, first_name_);
		std::cout << "Last name : ";
		std::getline(std::cin, last_name_);
		std::cout << "Nickname : ";
		std::getline(std::cin, nickname_);
		std::cout << "Phone number : ";
		std::getline(std::cin, phone_number_);
		std::cout << "Please, tell me your darkest secret : ";
		std::getline(std::cin, darkest_secret_);
	} while (!contact_is_valid());
}
