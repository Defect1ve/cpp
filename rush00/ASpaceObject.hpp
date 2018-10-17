#ifndef SPACE_OBJECT_HPP
# define SPACE_OBJECT_HPP
# include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <ncurses.h>

typedef struct	s_ammo
{
	int					x;
	int					y;
	char				*character;
	struct s_ammo		*next;
}				t_ammo;

class ASpaceObject
{
public:
	ASpaceObject(void);
	~ASpaceObject(void);
	virtual void	Shoot(WINDOW *win) = 0;
	int				get_X(void) const;
	int				get_Y(void) const;
	char			**getToken(void) const;
	t_ammo			*getAmmo() const;
	void			DrawAmmo(WINDOW *newwin, t_ammo *temp);

protected:
	
	char			**token;
	int				_x;
	int				_y;
	int	_row;
	int	_col;
	t_ammo			*ammo;
};

#endif