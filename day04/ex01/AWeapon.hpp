#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class	AWeapon
{
	protected:
	
		std::string		_NAME;
		unsigned int	_DAMAGE;
		unsigned int	_APCOST;

	public:

		AWeapon();
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const&src);
		virtual ~AWeapon();
		AWeapon & operator=(AWeapon const &src);
		std::string const & getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;
};

#endif