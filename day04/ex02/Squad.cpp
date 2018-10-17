# include "Squad.hpp"

Squad::Squad(void) : team(NULL), n(0) 
{

}

Squad::~Squad(void)
{
	for (int i = 0; i < this->getCount(); i++)
		delete this->team[i];
	delete [] this->team;
}

Squad::Squad(Squad const &src)
{
	*this = src;
}

Squad & Squad::operator=(Squad const &src)
{
	if (&src == this)
		return (*this);
	for (int i = 0; i < this->getCount(); i++)
		delete this->team[i];
	if (n)
		delete [] this->team;
	this->n = src.n;
	this->team = new ISpaceMarine*[n];
	for (unsigned int j = 0; j < this->n; j++)
		this->team[j] = src.team[j]->clone();
	return (*this);
}

int		Squad::getCount(void) const
{
	return (this->n);
}

ISpaceMarine*	Squad::getUnit(int member) const
{
	return (this->team[member]);
}

int				Squad::push(ISpaceMarine* marine)
{
	if (marine == NULL)
		return (this->n);
	ISpaceMarine** mass = new ISpaceMarine*[n + 1];
	for (unsigned int j = 0; j < this->n; j++)
		mass[j] = this->team[j];
	if (n)
		delete [] this->team;
	mass[getCount()] = marine;
	this->team = mass;
	this->n++;
	return (n);
}