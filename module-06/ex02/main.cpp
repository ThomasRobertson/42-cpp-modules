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
		std::cout << "Creating A\n";
		break;

	case 1:
		ptr = new B();
		std::cout << "Creating B\n";
		break;

	case 2:
		ptr = new C();
		std::cout << "Creating C\n";
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
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B& base_B = dynamic_cast<B&>(p);
		(void)base_B;
		std::cout << "Base is of type B&" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C& base_C = dynamic_cast<C&>(p);
		(void)base_C;
		std::cout << "Base is of type C&" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	for (int i = 0; i != 10; i++)
	{
		Base* new_base = generate();
		identify(new_base);
		delete new_base;
	}

	A base_A;
	B base_B;
	C base_C;
	identify(base_A);
	identify(base_B);
	identify(base_C);
}