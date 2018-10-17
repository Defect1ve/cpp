#ifndef ENEMY_HPP
# define ENEMY_HPP
# include "ASpaceObject.hpp"

class Enemy : public ASpaceObject
{
	public:
		Enemy();
		~Enemy();
		void	move(void);
		void	Shoot(WINDOW *win);
		Enemy & operator=(Enemy const &src);

		void	DrawEnemies(WINDOW *win);

	private:
		double			_arg;
};


#endif