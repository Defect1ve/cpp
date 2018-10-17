# include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) : _HP(hp), _TYPE(type)
{ }

Enemy::~Enemy(void)
{ }

Enemy::Enemy(Enemy const&src)
{
	*this = src;
}

Enemy & Enemy::operator=(Enemy const &src)
{
	this->_HP = src._HP;
	this->_TYPE = src._TYPE;
	return (*this);
}

std::string const Enemy::getType() const
{
	return (this->_TYPE);
}

int Enemy::getHP() const
{
	return (this->_HP);
}

void Enemy::takeDamage(int damage)
{
	if (damage > 0)
		this->_HP -= damage;
}