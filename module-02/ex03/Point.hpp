#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <string>

#include "Fixed.hpp"

class Point
{
	public:
		// Constructors
		Point();
		Point(const Point &copy);
		Point(const float x, const float y);
		
		// Destructor
		~Point();
		
		// Operators
		Point & operator=(const Point &assign);
		
		// Getters / Setters
		float getX() const;
		float getY() const;
		
	private:
		const Fixed _x;
		const Fixed _y;
		
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif