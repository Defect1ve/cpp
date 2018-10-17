#ifndef VICTIM_HPP
# define VICTIM_HPP
#include <iostream>

class	Victim
{
	public:

		Victim();
		Victim(std::string name);
		~Victim(void);
		Victim(Victim const &src);
		Victim & operator=(Victim const &src);
		std::string	getName(void) const;
		virtual void getPolymorphed(void) const; 

	protected:

		std::string	_NAME;
};

std::ostream &operator<<(std::ostream & o, Victim const &src);

#endif