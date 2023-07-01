#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	public:
		// Constructors
		Data();
		Data(const Data &copy);
		
		// Destructor
		~Data();
		
		// Operators
		Data & operator=(const Data &assign);
		
		// Getters / Setters
		double getPi() const;
		std::string getSecret() const;
		
	private:
		double _pi;
		std::string _secret;
		
};

#endif