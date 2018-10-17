#include "ASpaceObject.hpp"

ASpaceObject::ASpaceObject()
{
	token = new char*[5];
	for(int i = 0; i < 5; i++)
	{
		token[i] = new char[9];
	}
	ammo = NULL;
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	_row = size.ws_row;
	_col = size.ws_col;
}

ASpaceObject::~ASpaceObject()
{ }

t_ammo	*ASpaceObject::getAmmo(void) const
{
	return (this->ammo);
}

int		ASpaceObject::get_X(void) const
{
	return (this->_x);
}

int		ASpaceObject::get_Y(void) const
{
	return (this->_y);
}

char	**ASpaceObject::getToken(void) const
{
	return (this->token);
}

void	ASpaceObject::DrawAmmo(WINDOW *win, t_ammo *_ammo)
{
	mvwprintw(win, _ammo->y, _ammo->x, "%s", _ammo->character);
}