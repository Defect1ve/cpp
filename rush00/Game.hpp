#ifndef GAME_HPP
#define GAME_HPP
# include <ncurses.h>
# include <iostream>
# include "Spaceship.hpp"
# include "Enemy.hpp"
//# define abs(x)  (((x) < 0) ? (-x) : (x))

class Game
{
public:
	Game();
	Game(double speed, int start_x, int start_y);
	~Game();
	WINDOW  *win;
	void	FirstScreen(void);
	void	MainScreen();
	void	Controller(Spaceship *ship);
	void	Redraw(void);
	void	addEnemy(void);
	t_ammo	*delete_ammo(t_ammo *ammo, t_ammo *temp);
	int		MoveEnemies(Spaceship *ship);
	void	addEnemies(int i);
	void	checkCrashes(Spaceship *ship);
	void	GameOver(void);
	void	DrawMap(Spaceship ship);
private:

	Enemy			**enemies;
	double			_speed;
	int	rows;
	int	cols;
	int	_start_x;
	int	_start_y;
	unsigned char	_command;

};

#endif