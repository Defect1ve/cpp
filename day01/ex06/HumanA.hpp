#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
#include "Weapon.hpp"

class	HumanA
{
	public:

		HumanA(const std::string &str, Weapon  &weapon);
		void	attack(void);

	private:

		std::string	name;
		Weapon		&weapon;
};

#endif