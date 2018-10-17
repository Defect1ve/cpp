# include "Fixed.hpp"
# include <cmath>

const int Fixed::_fract_bits = 8;

Fixed::Fixed(const int val) : _fixed_point(val << _fract_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : _fixed_point(roundf(val * (float)(1 << _fract_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point / (float)(1 << this->_fract_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_fixed_point >> this->_fract_bits);
}

Fixed::Fixed(void) : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

std::ostream &operator<<( std::ostream & o, Fixed const &src)
{
	o << src.toFloat();
	return o;
}

Fixed & Fixed::operator=(Fixed const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed_point = src.getRawBits();
	return (*this);
}