#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
#include "Weapon.hpp"

class	HumanB
{
	public:

		HumanB(const std::string &str);
		void	attack(void);
		void	setWeapon(Weapon &weapon);

	private:

		Weapon		*weapon;
		std::string	name;
};

#endif