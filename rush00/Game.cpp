# include "Game.hpp"
#include <sys/ioctl.h>
#include <unistd.h>

Game::Game(void)
{ }

Game::Game(double speed, int start_x, int start_y) :  _speed(speed), _start_x(start_x), _start_y(start_y), _command(1)
{
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);

	win = NULL;
	enemies = new Enemy*[10];
	rows = size.ws_row;
	cols = size.ws_col;
}

Game::~Game(void)
{ }

void	Game::Controller(Spaceship *ship)
{
	nodelay(win, true);
	int c = wgetch(win);

	if (c == KEY_UP)
		ship->move(0, -1);
	else if (c == KEY_DOWN)
		ship->move(0, 1);
	else if (c == KEY_RIGHT)
		ship->move(1, 0);
	else if (c == KEY_LEFT)
		ship->move(-1, 0);
	else if (c == 32)
	{
		
		ship->Shoot(win);
	}

}

t_ammo	*Game::delete_ammo(t_ammo *ammo, t_ammo *temp)
{
	t_ammo	*prev;

	prev = ammo;
	while (prev && prev->next && prev->next != temp)
	{
		prev = prev->next;
	}
	if (prev && prev->next)
		prev->next = temp->next;
	if(temp)
	{
		delete temp;
		temp = NULL;
	}
	std::cout << "help" << std::endl;
	return prev;
}


void	Game::addEnemies(int i)
{
	int k = 0;
	srand(time(0));
	while (i--)
		if (rand() % 10 > 8)
		{
			Enemy *temp = new Enemy;

			
			while (enemies[k] != NULL)
				k++;
			enemies[k] = temp;
		}
}

void	Game::GameOver(void)
{
	exit(0);
}

int		Game::MoveEnemies(Spaceship *ship)
{
	int num = 0;
	for (int i = 0; i < 10; i++)
	{
		if (enemies[i] != NULL)
		{
			enemies[i]->move();
		}
		else
			num++;
		if (enemies[i] != NULL && (enemies[i]->get_X() < 1 || enemies[i]->get_Y() < 0))
		{
			mvwprintw(win, enemies[i]->get_Y() + 1, enemies[i]->get_X(), "       ");
			mvwprintw(win, enemies[i]->get_Y() + 2, enemies[i]->get_X(), "       ");
			mvwprintw(win, enemies[i]->get_Y() + 3, enemies[i]->get_X(), "       ");
			
			ship->ReduceHP();
			delete enemies[i];
			enemies[i] = NULL;
		}
	}
	return (num);
}

void	Game::checkCrashes(Spaceship *ship)
{
	int a;
	t_ammo		*temp;
	temp = ship->getAmmo();
	char	**token;

	for(int k = 0; k < 10; k++)
	{
		if(enemies[k] != NULL)
		{
			token = enemies[k]->getToken();
			while (temp)
			{
				for (int i = 0; i < 5; i++)
					for (int j = 0; j < 7; j++)
					{
						if (enemies[k] && (token[i][j] != ' ') && temp->x == (j + enemies[k]->get_X()) && temp->y == i + enemies[k]->get_Y())
						{
							delete enemies[k];
							enemies[k] = NULL;
							ship->setScore(1);
						}
					}
					if(temp)
						temp = temp->next;
			}
		}
	}
	for (int k = 0; k < 10; k++)
		
		if(enemies[k] != NULL)
		{
			if ((std::abs(enemies[k]->get_X() - ship->get_X())) < 5 && std::abs(enemies[k]->get_Y() - ship->get_Y()) < 3)
			{
				GameOver();
			}
		}
}

void	Game::DrawMap(Spaceship ship)
{
	t_ammo *temp = ship.getAmmo();

	box(win, ' ', 0);
	refresh();
	wrefresh(win);
	ship.DrawShip(win);
	for(int i = 0; i < 10; i++)
	{
		if(enemies[i] != NULL)
		{
			enemies[i]->DrawEnemies(win);
		}
	}
	while(temp)
	{
		temp->x += 2;
		ship.DrawAmmo(win, temp);
		temp = temp->next;
	}


}

void	Game::MainScreen()
{
	Spaceship	ship;
	int			freeEnemies;
	struct winsize size;
	win = newwin(rows - 14, cols, 7, _start_x);
	keypad(win, TRUE);
	for (int i = 0; i < 10; i++)
		enemies[i] = NULL;
	while (1)
	{
		ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
		noecho();
		usleep(30000);
		clear();
		refresh();
		wrefresh(win);
		Controller(&ship);
		freeEnemies = MoveEnemies(&ship);
		if (freeEnemies)
			addEnemies(freeEnemies);
		checkCrashes(&ship);
		DrawMap(ship);
		mvwprintw(win, 1, 3, "HP: %d     Score: %d", ship.getHp(), ship.getScore());
	}
}

void	Game::FirstScreen(void)
{
	initscr();
	struct winsize size;
	int color;
	int c = 0;

	win = newwin(size.ws_row, size.ws_col, _start_y, _start_x);
	
	curs_set(0);
	noecho();
	keypad(win, TRUE);
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	while (1)
	{
		ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
		usleep(20000);
		clear();
		nodelay(win, true);
		color = rand() % 6;
		wattron(win, COLOR_PAIR(color));
		mvwprintw(win, (size.ws_row - 8) / 4, (size.ws_col - 74) / 2, "  /$$$$$$   /$$                                /$$                        \n");
	 	mvwprintw(win, (size.ws_row - 8) / 4 + 1, (size.ws_col - 74) / 2, " /$$__  $$ | $$                               | $$                        \n");
	 	mvwprintw(win, (size.ws_row - 8) / 4 + 2, (size.ws_col - 74) / 2, "| $$  \\__//$$$$$$         /$$$$$$   /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ \n");
	 	mvwprintw(win, (size.ws_row - 8) / 4 + 3, (size.ws_col - 74) / 2, "| $$$$   |_  $$_/        /$$__  $$ /$$__  $$|_  $$_/   /$$__  $$ /$$__  $$\n");
	 	mvwprintw(win, (size.ws_row - 8) / 4 + 4, (size.ws_col - 74) / 2, "| $$_/     | $$         | $$  \\__/| $$$$$$$$  | $$    | $$  \\__/| $$  \\ $$\n");
	 	mvwprintw(win, (size.ws_row - 8) / 4 + 5, (size.ws_col - 74) / 2, "| $$       | $$ /$$     | $$      | $$_____/  | $$ /$$| $$      | $$  | $$\n");
	 	mvwprintw(win, (size.ws_row - 8) / 4 + 6, (size.ws_col - 74) / 2, "| $$       |  $$$$/     | $$      |  $$$$$$$  |  $$$$/| $$      |  $$$$$$/\n");
	 	mvwprintw(win, (size.ws_row - 8) / 4 + 7, (size.ws_col - 74) / 2, "|__/        \\___//$$$$$$|__/       \\_______/   \\___/  |__/       \\______/ \n");
	 	mvwprintw(win, (size.ws_row - 8) / 4 + 8, (size.ws_col - 74) / 2, "                |______/                                                  \n");
		wattroff(win, COLOR_PAIR(color));
		mvwprintw(win, (size.ws_row - 8) / 4 + 20, (size.ws_col - 9) / 2, "START");
		mvwprintw(win, (size.ws_row - 8) / 4 + 22, (size.ws_col - 9) / 2, "MULTIPLAYER");
		mvwprintw(win, (size.ws_row - 8) / 4 + 24, (size.ws_col - 9) / 2, "EXIT");
		wattron(win, COLOR_PAIR(6));
		if (_command == 1)
			mvwprintw(win, (size.ws_row - 8) / 4 + 20, (size.ws_col - 9) / 2 - 2, "> START");
		else if (_command == 2)
			mvwprintw(win, (size.ws_row - 8) / 4 + 22, (size.ws_col - 9) / 2 - 2, "> MULTIPLAYER");
		else if (_command == 0)
			mvwprintw(win, (size.ws_row - 8) / 4 + 24, (size.ws_col - 9) / 2 - 2, "> EXIT");
		wattroff(win, COLOR_PAIR(6));
		refresh();
		wrefresh(win);
		c = wgetch(win);
		if (c == KEY_UP)
			_command = (_command + 2) % 3;
		else if (c == KEY_DOWN)
			_command = (_command + 1) % 3;
		else if (c == 10)
		{
			if (_command == 0)
			{
				endwin();
				exit(0);
			}
			else if (_command == 1)
			{
				MainScreen();
			}
			else if (_command == 2)
			{
				;
			}
		}
	}
	endwin();
}