#include "Point.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);

	Point p[] = {Point(10, 15), Point(20, 15), Point(10, 30), Point(0,0), Point(-10,-20)};
	std::string answer[] = {"Inside", "Outside", "Outside (edge)", "Outside (edge)", "Outside"};
	for (size_t i = 0; i != (sizeof(p) / sizeof(*p)); i++)
	{
		if (bsp(a, b, c, p[i]))
			std::cout << "Point is inside." << std::endl;
		else
			std::cout << "Point is outside." << std::endl;
		if (i < sizeof(answer) / sizeof(*answer))
			std::cout << "Correct answer : " << answer[i] << std::endl << std::endl;
	}
	return 0;
}
