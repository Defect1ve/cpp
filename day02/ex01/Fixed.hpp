#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:

		Fixed();
		~Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(Fixed const &src);
		float toFloat(void) const;
		int		toInt( void ) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed & operator=(Fixed const &src);

	private:

		int					_fixed_point;
		static const int	_fract_bits;

};

std::ostream &operator<<(std::ostream & o, Fixed const &src);

# endif