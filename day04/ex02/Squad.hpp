#ifndef SQUAD_HPP
# define SQUAD_HPP
# include <iostream>
# include "ISquad.hpp"

class	Squad : public ISquad
{
	public:

		Squad();
		Squad(Squad const&src);
		virtual ~Squad();
		Squad & operator=(Squad const &src);
		int				getCount() const;
		ISpaceMarine*	getUnit(int member) const;
		int				push(ISpaceMarine* marine);

	private:

		ISpaceMarine**	team;
		unsigned int	n;
};

#endif