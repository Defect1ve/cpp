# include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy() : _mass(new OfficeBlock[20])
{ }

CentralBureaucracy::~CentralBureaucracy()
{
	for (int i = 0; i < 20;i++)
		if (_mass[i].getIntern())
			delete _mass[i].getIntern();
	delete [] _mass;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &src)
{
	*this = src;
}

CentralBureaucracy &CentralBureaucracy::operator=(CentralBureaucracy const &src)
{
	this->_mass = src._mass;
	return (*this);
}

void			CentralBureaucracy::FillBur(Bureaucrat const&bur)
{
	int i = -1;
	while (++i < 20)
	{
		if (!(_mass[i].getExecutor()))
			_mass[i].setExecutor(bur);
		else if (!(_mass[i].getSigner()))
			_mass[i].setSigner(bur);
		if (!(_mass[i].getIntern()))
		{
			Intern *trash = new Intern;
			_mass[i].setIntern(*trash);
		}
	}
	if (_mass_count < 20)
		_mass_count++;
}

void			CentralBureaucracy::queueUp(std::string name)
{
	t_queue *tmp;
	if (!my)
	{
		my = new t_queue;
		tmp = my;
	}
	else
	{
		tmp = my;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new t_queue;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->target = name;
}

std::string		CentralBureaucracy::getFirst(void)
{
	t_queue *tmp;
	std::string str;

	tmp = my;
	my = my->next;
	str = tmp->target;
	delete tmp;
	return (str);
}

CentralBureaucracy::EmptyOfficeException::EmptyOfficeException()
{ }

CentralBureaucracy::EmptyOfficeException::~EmptyOfficeException() throw()
{ }

CentralBureaucracy::EmptyOfficeException::EmptyOfficeException(EmptyOfficeException const&src)
{
	(void)src;
}

void	CentralBureaucracy::EmptyOfficeException::operator=(EmptyOfficeException const&src)
{
	(void)src;
}

const char *CentralBureaucracy::EmptyOfficeException::what() const throw()
{
	return ("There is no office block with bureaucrators...");
}

void			CentralBureaucracy::doBureaucracy(void)
{
	std::string arg[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	try
	{
		if (!(_mass[0].getSigner()) && !(_mass[0].getExecutor()))
			throw EmptyOfficeException();
		while (my)
			_mass[rand() % _mass_count].doBureaucracy(arg[rand() % 3], getFirst());
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}