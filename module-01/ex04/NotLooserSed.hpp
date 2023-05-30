#ifndef NotLooserSed_HPP
# define NotLooserSed_HPP

#include <string>

#include <iostream>
#include <sstream>
#include <fstream>

class NotLooserSed
{
	public:
	void replace(std::string from, std::string to);
	void exportToFile(std::ofstream &out);
	NotLooserSed(std::ofstream &in);

	private :
	std::string _str;
};

#endif
