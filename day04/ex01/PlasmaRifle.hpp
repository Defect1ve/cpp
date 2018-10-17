#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP
# include <iostream>
# include "AWeapon.hpp"

class	PlasmaRifle : public AWeapon
{
	public:

		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const&src);
		virtual ~PlasmaRifle();
		PlasmaRifle & operator=(PlasmaRifle const &src);
		void attack() const;
};

#endif