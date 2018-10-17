#ifndef SPACESHIP_HPP
# define SPACESHIP_HPP
#include "ASpaceObject.hpp"

class Spaceship : public ASpaceObject
{
public:
	Spaceship();
	~Spaceship();
	void			ReduceHP(void);
	virtual void	Shoot(WINDOW *win);
	virtual void	move(int x, int y);
	void			DrawShip(WINDOW *win);
	int				getHp() const;
	int				getScore() const;
	void			setScore(int n);

private:

	int	_hp;
	int	_score;
};

#endif