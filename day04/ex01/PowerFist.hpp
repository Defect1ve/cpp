#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP
# include <iostream>
# include "AWeapon.hpp"

class	PowerFist : public AWeapon
{
	public:

		PowerFist();
		PowerFist(PowerFist const&src);
		virtual ~PowerFist();
		PowerFist & operator=(PowerFist const &src);
		void attack() const;
};

#endif