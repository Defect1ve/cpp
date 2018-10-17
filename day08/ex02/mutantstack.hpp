#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
#include <algorithm>
#include <iostream>
#include <list>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:
	
public:
	MutantStack()
	{ }
	MutantStack(MutantStack const&src) : std::stack<T>(src)
	{ }
	MutantStack &operator=(MutantStack const &src)
	{
		if (this != &src)
			std::stack<T>::operator=(src);
		return (*this);
	}
	~MutantStack()
	{ }
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
	const_iterator begin() const
	{
		return (this->c.cbegin());
	}
	const_iterator end() const
	{
		return (this->c.cend());
	}
};

#endif