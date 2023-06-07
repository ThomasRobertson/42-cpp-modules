#include "Point.hpp"

// Constructors
Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y)
{
}

Point::Point(const float x, const float y)  : _x(x), _y(y)
{
}

// Destructor
Point::~Point()
{
}


// Operators
Point & Point::operator=(const Point &assign)
{
	(void)assign;
	std::cerr << "Can not assign to const member. Nothing changed." << std::endl;
	return *this;
}

// Getters / Setters
float Point::getX() const
{
	return _x.toFloat();
}
float Point::getY() const
{
	return _y.toFloat();
}
