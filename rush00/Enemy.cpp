# include "Enemy.hpp"
# include <math.h>

Enemy::Enemy(void) : ASpaceObject()
{
	srand(time(0));
	ammo = NULL;
	_arg = 0;
	_x = _col - 10;
	_y = _row * (rand() % 8 + 1) / 10;

	strcpy(token[0], "       ");
	strcpy(token[1], "  ()() ");
	strcpy(token[2], "()()() ");
	strcpy(token[3], "  ()() ");
	strcpy(token[4], "       ");
}

Enemy::~Enemy(void)
{ }

Enemy & Enemy::operator=(Enemy const &src)
{
	this->_arg = src._arg;
	return (*this);
}

void	Enemy::move()
{
	_x -= 1;
	}

void	Enemy::Shoot(WINDOW *win)
{
	t_ammo	*temp;
	if (!ammo)
	{
		ammo = new t_ammo;
		temp = ammo;
	}
	else
	{
		temp = ammo;
		while (temp->next)
			temp = temp->next;
		temp->next = new t_ammo;
		temp = temp->next;
	}
	temp->next = NULL;
	temp->x = _x - 1;
	temp->y = _y + 1;
	temp->character = strdup("* ");
}

void	Enemy::DrawEnemies(WINDOW *win)
{
	for(int i = 0; i < 5; i++)
	{
		mvwprintw(win, _y + i, _x, "%.7s", token[i]);
	}
}