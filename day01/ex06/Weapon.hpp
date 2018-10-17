#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>

class	Weapon
{
	public:

		Weapon(void);
		Weapon(const std::string &str);
		std::string &getType(void);
		void		setType(const std::string &str);

	private:
		std::string	type;
};

#endif