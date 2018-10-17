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
		bool	operator>(Fixed const &src);
		bool	operator<(Fixed const &src);
		bool	operator>=(Fixed const &src);
		bool	operator<=(Fixed const &src);
		bool	operator==(Fixed const &src);
		bool	operator!=(Fixed const &src);
		Fixed	operator+(Fixed const &src);
		Fixed	operator-(Fixed const &src);
		Fixed	operator/(Fixed const &src);
		Fixed	operator*(Fixed const &src);
		Fixed const operator++(void);
		Fixed const operator++(int);
		Fixed const operator--(void);
		Fixed const operator--(int);
		static Fixed const &min(Fixed const &src1, Fixed const &src2);
		static Fixed &min(Fixed &src1, Fixed &src2);
		static Fixed const &max(Fixed const &src1, Fixed const &src2);
		static Fixed &max(Fixed &src1, Fixed &src2);

	private:

		int					_fixed_point;
		static const int	_fract_bits;

};

std::ostream &operator<<(std::ostream & o, Fixed const &src);

# endif