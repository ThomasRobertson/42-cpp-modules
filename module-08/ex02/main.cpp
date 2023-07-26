#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <vector>

template <class T, class Container>
void test_container()
{
	MutantStack<T, Container> mstack;

	mstack.push(1);
	mstack.push(2);
	std::cout << "Last item : " << mstack.top() << std::endl;
	std::cout << "Total size : " << mstack.size() << std::endl;
	
	mstack.pop();
	std::cout << "Total size after pop : " << mstack.size() << std::endl;
	std::cout << "Last item : " << mstack.top() << std::endl;

	for (int i = 2; i != 10; i++)
		mstack.push(static_cast<T>(i));

	typename MutantStack<T, Container>::iterator it = mstack.begin();
	typename MutantStack<T, Container>::iterator ite = mstack.end();
	std::cout << "\n--- ITERATOR ---"
		<< "\nFirst item : " << *it++
		<< "\nSecond item : " << *it--
		<< "\nLast item : " << *(--ite) << std::endl;
		/* << "\nFirst adress : " << &it
		<< "\nLast adress : " << &ite << std::endl; */

	++it;
	--it;
	++ite;

	typename MutantStack<T, Container>::const_iterator const_it = mstack.begin();
	typename MutantStack<T, Container>::const_iterator const_ite = mstack.end();
	std::cout << "\n--- CONST ITERATOR ---"
		<< "\nFirst item : " << *const_it++
		<< "\nSecond item : " << *const_it--
		<< "\nLast item : " << *(--const_ite) << std::endl;

	++const_ite;

	std::cout << "\n--- ITERATOR LOOP ---\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		*it = *it + static_cast<T>(10);
		++it;
	}

	std::cout << "\n--- CONST ITERATOR LOOP ---\n";
	while (const_it != const_ite)
	{
		std::cout << *const_it << std::endl;
		// *const_it += 10; not working
		++const_it;
	}

	std::stack<T, Container> s(mstack);
	return ;	
}

template <class Container>
void test_container_string()
{
	MutantStack<std::string, Container> mstack;

	mstack.push("1");
	mstack.push("2");
	std::cout << "Last item : " << mstack.top() << std::endl;
	std::cout << "Total size : " << mstack.size() << std::endl;
	
	mstack.pop();
	std::cout << "Total size after pop : " << mstack.size() << std::endl;
	std::cout << "Last item : " << mstack.top() << std::endl;

	std::string arr[] = {"2", "3", "4", "5", "6", "7", "8", "9"};
	for (int i = 2; i != (sizeof arr / sizeof *arr); i++)
		mstack.push(arr[i]);

	typename MutantStack<std::string, Container>::iterator it = mstack.begin();
	typename MutantStack<std::string, Container>::iterator ite = mstack.end();
	std::cout << "\n--- ITERATOR ---"
		<< "\nFirst item : " << *it++
		<< "\nSecond item : " << *it--
		<< "\nLast item : " << *(--ite) << std::endl;
		/* << "\nFirst adress : " << &it
		<< "\nLast adress : " << &ite << std::endl; */

	++it;
	--it;
	++ite;

	typename MutantStack<std::string, Container>::const_iterator const_it = mstack.begin();
	typename MutantStack<std::string, Container>::const_iterator const_ite = mstack.end();
	std::cout << "\n--- CONST ITERATOR ---"
		<< "\nFirst item : " << *const_it++
		<< "\nSecond item : " << *const_it--
		<< "\nLast item : " << *(--const_ite) << std::endl;

	++const_ite;

	std::cout << "\n--- ITERATOR LOOP ---\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		*it += "toto";
		++it;
	}

	std::cout << "\n--- CONST ITERATOR LOOP ---\n";
	while (const_it != const_ite)
	{
		std::cout << *const_it << std::endl;
		// *const_it += 10; not working
		++const_it;
	}

	std::stack<std::string, Container> s(mstack);
	std::cout << std::endl;
	return ;	
}

int main()
{
	std::cout << "----- INT / DEQUE -----\n\n";
	test_container<int, std::deque<int> > ();
	std::cout << "\n----- FLOAT / DEQUE -----\n\n";
	test_container<float, std::deque<float> > ();
	std::cout << "\n----- DOUBLE / DEQUE -----\n\n";
	test_container<double, std::deque<double> > ();
	std::cout << "\n----- BOOL / DEQUE -----\n\n";
	test_container<bool, std::deque<bool> > ();
	std::cout << "\n----- STRING / DEQUE -----\n\n";
	test_container_string<std::deque<std::string> > ();

	std::cout << "----- INT / LIST -----\n\n";
	test_container<int, std::list<int> > ();
	std::cout << "\n----- FLOAT / LIST -----\n\n";
	test_container<float, std::list<float> > ();
	std::cout << "\n----- DOUBLE / LIST -----\n\n";
	test_container<double, std::list<double> > ();
	std::cout << "\n----- BOOL / LIST -----\n\n";
	test_container<bool, std::list<bool> > ();
	std::cout << "\n----- STRING / LIST -----\n\n";
	test_container_string<std::list<std::string> > ();

	std::cout << "----- INT / VECTOR -----\n\n";
	test_container<int, std::vector<int> > ();
	std::cout << "\n----- FLOAT / VECTOR -----\n\n";
	test_container<float, std::vector<float> > ();
	std::cout << "\n----- DOUBLE / VECTOR -----\n\n";
	test_container<double, std::vector<double> > ();
	std::cout << "\n----- BOOL / VECTOR -----\n\n";
	test_container<bool, std::vector<bool> > ();
	std::cout << "\n----- STRING / VECTOR -----\n\n";
	test_container_string<std::vector<std::string> > ();
}
