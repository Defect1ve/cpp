# include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _intern(NULL), _signer(NULL), _executor(NULL)
{ }

OfficeBlock::OfficeBlock(Intern * intern, Bureaucrat *signer, Bureaucrat*executor) : _intern(intern), _signer(signer), _executor(executor)
{ }

OfficeBlock::~OfficeBlock()
{ }

OfficeBlock::PointerException::PointerException()
{ }

OfficeBlock::PointerException::~PointerException() throw()
{ }

OfficeBlock::PointerException::PointerException(PointerException const &src)
{
	(void)src;
}

void OfficeBlock::PointerException::operator=(PointerException const &src)
{
	(void)src;
}

const char *OfficeBlock::PointerException::what() const throw()
{
	return ("Invalid poiner!");
}

void	OfficeBlock::setIntern(Intern const &intern)
{
	this->_intern = &intern;
}

void	OfficeBlock::setSigner(Bureaucrat const &bur)
{
	this->_signer = &bur;
}

void	OfficeBlock::setExecutor(Bureaucrat const &bur)
{
	this->_executor = &bur;
}

Intern const *OfficeBlock::getIntern(void)
{
	return (this->_intern);
}

Bureaucrat const *OfficeBlock::getSigner(void)
{
	return (this->_signer);
}

Bureaucrat const *OfficeBlock::getExecutor(void)
{
	return (this->_executor);
}

void		OfficeBlock::doBureaucracy(std::string name, std::string target)
{
	try
	{
		if (!_intern || !_signer || !_executor)
			throw PointerException();
		AForm *tmp;
		if (!(tmp = _intern->makeForm(name, target)))
			throw Intern::WrongTypeException();
		_signer->signForm(*tmp);
		_executor->executeForm(*tmp);
		delete tmp;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}