#ifndef WARRIOR_HPP
# define WARRIOR_HPP
#include "Victim.hpp"

class	Warrior : public Victim
{
	public:
	Warrior(void);
	Warrior(std::string name);
	~Warrior(void);
	Warrior(Warrior const &src);
	Warrior & operator=(Warrior const &src);
	virtual void getPolymorphed(void) const;
};

#endif