#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
	public:
	std::string get_first_name () const;
	std::string get_last_name () const;
	std::string get_nickname () const;
	std::string get_phone_number () const;
	std::string get_darkest_secret () const;

	void set_contact();
	void display_contact();

	private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;

	bool contact_is_valid();
};

#endif
