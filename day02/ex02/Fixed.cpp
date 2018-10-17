# include "Fixed.hpp"
# include <cmath>

const int Fixed::_fract_bits = 8;

Fixed::Fixed(const int val) : _fixed_point(val << _fract_bits)
{ }

Fixed::Fixed(const float val) : _fixed_point(roundf(val * (float)(1 << _fract_bits)))
{ }

float Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point / (float)(1 << this->_fract_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_fixed_point >> this->_fract_bits);
}

Fixed::Fixed(void) : _fixed_point(0)
{ }

Fixed::~Fixed(void)
{ }

Fixed::Fixed(Fixed const &src)
{
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
	this->_fixed_point = src.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &src)
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(Fixed const &src)
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &src)
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &src)
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

bool	Fixed::operator>(Fixed const &src)
{
	if (this->toFloat() > src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &src)
{
	if (this->toFloat() < src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &src)
{
	if (this->toFloat() >= src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &src)
{
	if (this->toFloat() <= src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &src)
{
	if (this->toFloat() == src.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &src)
{
	if (this->toFloat() != src.toFloat())
		return (true);
	return (false);
}

Fixed const Fixed::operator++(void)
{
	this->_fixed_point++;
	return *this;
}

Fixed const Fixed::operator--(void)
{
	this->_fixed_point--;
	return *this;
}

Fixed const Fixed::operator++(int)
{
	Fixed const tmp(*this);
	this->_fixed_point++;
	return tmp;
}

Fixed const Fixed::operator--(int)
{
	Fixed const tmp(*this);
	this->_fixed_point--;
	return tmp;
}

Fixed const &Fixed::min(Fixed const &src1, Fixed const &src2)
{
	if (src1.toFloat() > src2.toFloat())
		return (src2);
	return (src1);
}

Fixed &Fixed::min(Fixed &src1, Fixed &src2)
{
	if (src1.toFloat() > src2.toFloat())
		return (src2);
	return (src1);
}

Fixed const &Fixed::max(Fixed const &src1, Fixed const &src2)
{
	if (src1.toFloat() < src2.toFloat())
		return (src2);
	return (src1);
}

Fixed &Fixed::max(Fixed &src1, Fixed &src2)
{
	if (src1.toFloat() < src2.toFloat())
		return (src2);
	return (src1);
}