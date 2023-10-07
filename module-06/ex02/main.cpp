#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <string>
#include <iostream>
#include <cstdlib>

Base *generate(void)
{
	Base *ptr = 0;
	switch (::rand() % 3)
	{
	case 0:
		ptr = new A();
		std::cout << "Creating A : ";
		break;

	case 1:
		ptr = new B();
		std::cout << "Creating B : ";
		break;

	case 2:
		ptr = new C();
		std::cout << "Creating C : ";
		break;

	default:
		break;
	}
	return ptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Base is of type A*" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Base is of type B*" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Base is of type C*" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A& base_A = dynamic_cast<A&>(p);
		(void)base_A;
		std::cout << "Base is of type A&" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B& base_B = dynamic_cast<B&>(p);
		(void)base_B;
		std::cout << "Base is of type B&" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C& base_C = dynamic_cast<C&>(p);
		(void)base_C;
		std::cout << "Base is of type C&" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	std::cout << "-- Testing pointers --\n\n";
	for (int i = 0; i != 10; i++)
	{
		Base* new_base = generate();
		identify(new_base);
		delete new_base;
	}

	std::cout << "\n-- Testing reference --\n\n";
	std::cout << "Creating object A\n";
	A base_A;
	identify(base_A);
	std::cout << "Creating object B\n";
	B base_B;
	identify(base_B);
	std::cout << "Creating object C\n";
	C base_C;
	identify(base_C);
}