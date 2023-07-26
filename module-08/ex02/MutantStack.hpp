#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>
#include <deque>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :

/* 	typedef TIterator<iterator> iterator;
	typedef TIterator<const_iterator> const_iterator; */
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	//typedef void * iterator;
	MutantStack() {}
	MutantStack(const MutantStack & copy) {*this = copy;}
	~MutantStack() {}
	MutantStack & operator=(const MutantStack & assign) {(void)assign;};

	iterator end() {return std::stack<T, Container>::c.end();}
	iterator begin() {return std::stack<T, Container>::c.begin();}
	
	private :
/* 	template <typename PointerType>
	class TIterator : public Container::PointerType
	{

	}; */
};

#endif // !MUTANT_STACK_HPP