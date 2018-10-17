#ifndef	PONY_HPP
# define PONY_HPP

class	Pony{
	public:

		Pony(int a, int b);
		~Pony();
		void	SayHello(void);

	private:

	int		_height;
	int		_weight;
};
#endif