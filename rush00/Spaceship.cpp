# include "Spaceship.hpp"

Spaceship::Spaceship(void) : ASpaceObject()
{
	ammo = NULL;
	_hp = 100;
	_score = 0;
	_x = 0;
	_y = (_row - 14) / 2;
	strcpy(token[0], "       ");
	strcpy(token[1], " |\\   ");
	strcpy(token[2], " |#|=> ");
	strcpy(token[3], " |/    ");
	strcpy(token[4], "       ");
}

Spaceship::~Spaceship(void)
{ }

void	Spaceship::move(int x, int y)
{
	if (_x + x < _col - 10 && _x + x >= 0)
	{
		_x += x;
	}
	if (_y + y < _row - 17 && _y + y >= 1)
		_y += y;
}

void	Spaceship::ReduceHP(void)
{
	this->_hp--;
}

void	Spaceship::Shoot(WINDOW *win)
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
		temp->x = _x + 5;
		temp->y = _y + 2;
		temp->character = strdup("  - ");
	}


void			Spaceship::DrawShip(WINDOW *win)
{
	for(int i = 0; i < 5; i++)
	{
		mvwprintw(win, _y + i, _x + 1, "%s", token[i]);
	}
}

int		Spaceship::getHp() const
{
	return _hp;
}

int		Spaceship::getScore() const 
{
	return _score;
}

void	Spaceship::setScore(int num) 
{
	_score += num;
}