#ifndef	CHARACTER_HPP
# define CHARACTER_HPP
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:

		std::string		_NAME;
		unsigned int	_AP;
		AWeapon			*_WEAPON;

	public:

		Character();
		Character(std::string const & name);
		Character(Character const &src);
		Character & operator=(Character const &src);
		~Character();
		void recoverAP();
		void equip(AWeapon* weapon);
		void attack(Enemy* enemy);
		std::string const	&getName() const;
		AWeapon*			getWeapon() const;
		unsigned int		getAP() const;
};

std::ostream &operator<<(std::ostream & o, Character const &src);

#endif