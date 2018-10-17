#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>

class Enemy
{
	private:

	unsigned int	_HP;
	std::string		_TYPE;

	public:
		Enemy();
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		Enemy(Enemy const &src);
		Enemy & operator=(Enemy const &src);
		std::string const getType() const;
		int getHP() const;
		virtual void takeDamage(int damage);
};

#endif