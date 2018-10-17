#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<typename T>
class Array
{
private:
	unsigned int size_array;
	T	*mass;
public:
	
	class OutOfLimits : public std::exception
	{
		public:
			OutOfLimits(void)
			{ }
			virtual ~OutOfLimits() throw()
			{ }
			OutOfLimits(OutOfLimits const &src)
			{ (void)src;}
			void operator=(OutOfLimits const &src)
			{ (void)src;}
			virtual const char * what() const throw()
			{
				return ("Your index is out of limits");
			}
	};
	unsigned int size(void) const{
		return (this->size_array);
	}
	Array<T>(void) {
		this->mass = new T[0];
		size_array = 0;
	}
	Array<T>(unsigned int n){
		this->mass = new T[n];
		size_array = n;
	}
	Array<T>(Array const &src){
		this->mass = new T[src.size()];
		for (unsigned int i = 0; i < src.size(); i++)
			mass[i] = src.mass[i];
		this->size_array = src.size();
	}
	Array &operator=(Array const &src){
		if (this != &src)
			delete [] this->mass;
		this->mass = new T[src.size()];
		for (unsigned int i = 0; i < src.size(); i++)
			mass[i] = src.mass[i];
		this->size_array = src.size();
		return (*this);
	}
	T			&operator[](unsigned int i)
	{
		if (i >= this->size_array)
			throw OutOfLimits();
		return (mass[i]);
	}
	~Array(){
		delete [] mass;
	}
};



#endif