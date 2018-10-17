#ifndef PEON_HPP
# define PEON_HPP
#include "Victim.hpp"

class	Peon : public Victim
{
	public:
	Peon(void);
	Peon(std::string name);
	~Peon(void);
	Peon(Peon const &src);
	Peon & operator=(Peon const &src);
	virtual void getPolymorphed(void) const;
};

#endif