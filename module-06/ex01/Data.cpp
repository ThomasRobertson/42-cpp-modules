#include "Data.hpp"

Data::Data()
{
	_pi = 3.14;
	_secret = "I hate pasta";
}

Data::Data(const Data &copy)
{
	_pi = copy._pi;
	_secret = copy._secret;
}

Data::~Data()
{
}

Data & Data::operator=(const Data &assign)
{
	if (this != &assign)
	{
		_pi = assign._pi;
		_secret = assign._secret;
	}
	return *this;
}

double Data::getPi() const
{
	return _pi;
}
std::string Data::getSecret() const
{
	return _secret;
}
