#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	std::cout << "PHON-O-MATRON PhoneBook v2.1a" << std::endl ;
	std::cout << "Copyright 1999 - 42 Inc." << std::endl << std::endl;
	std::cout << "Loading ressources..." << std::endl << std::endl;

	PhoneBook main_phonebook;

	std::cout << std::endl << "Please use the following commands :" << std::endl;
	std::cout << "ADD : Save a new contact" << std::endl;
	std::cout << "SEARCH : display a specific contact." << std::endl;
	std::cout << "EXIT : Exit the program." << std::endl << std::endl;

	std::string input;
	do {
		std::cout << "CMD : ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		main_phonebook.execute_input(input);
	}
	while (input != "EXIT");
}