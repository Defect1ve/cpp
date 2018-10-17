#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:

		Fixed();
		~Fixed();
		Fixed(Fixed const &src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed & operator=(Fixed const &src);

	private:

		int					_fixed_point;
		static const int	_fract_bits;

};

# endif