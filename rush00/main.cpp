# include "Enemy.hpp"
# include "Spaceship.hpp"
# include "ASpaceObject.hpp"
# include "Game.hpp"
# include <unistd.h>

int		main(void)
{
	srand(time(NULL));
	Game	game(1.0, 0, 0);

	game.FirstScreen();
	return (0);
}