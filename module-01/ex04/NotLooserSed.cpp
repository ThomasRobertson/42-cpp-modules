#include "NotLooserSed.hpp"

void NotLooserSed::replace(std::string from, std::string to)
{
	std::string str_out;
	std::string::size_type new_pos;
	std::string::size_type previus_pos = 0;

	while ((new_pos = _str.find(from, previus_pos)) != std::string::npos)
	{
		str_out.append(_str, previus_pos, new_pos - previus_pos);
		str_out.append(to);
		previus_pos = new_pos + from.length();
	}
	str_out.append(_str, previus_pos);
	_str = str_out;
}

void NotLooserSed::exportToFile(std::ofstream &out)
{
	out << _str;
}

NotLooserSed::NotLooserSed(std::ofstream &in)
{
    std::stringstream ss;

    ss << in.rdbuf();
    _str = ss.str();
}
