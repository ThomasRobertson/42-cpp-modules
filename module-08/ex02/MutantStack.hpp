#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>
#include <deque>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	MutantStack() {}
	MutantStack(const MutantStack & copy) {*this = copy;}
	~MutantStack() {}
	MutantStack & operator=(const MutantStack & assign) {
        std::stack<T, Container>::operator=(assign);
        return *this;
	}

	iterator end() {return std::stack<T, Container>::c.end();}
	const_iterator end() const {return std::stack<T, Container>::c.end();}
	iterator begin() {return std::stack<T, Container>::c.begin();}
	const_iterator begin() const {return std::stack<T, Container>::c.begin();}
};

#endif // !MUTANT_STACK_HPP